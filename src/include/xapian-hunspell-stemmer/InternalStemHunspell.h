//
// Created by piotr on 14.11.16.
//

#ifndef XAPIAN_HUNSPELL_STEMMER_INTERNALSTEMHUNSPELL_H
#define XAPIAN_HUNSPELL_STEMMER_INTERNALSTEMHUNSPELL_H

#include <xapian/stem.h>
#include <hunspell.h>
#include "IconvWrapper.h"

namespace Xapian {

    class InternalStemHunspell : public StemImplementation {
    public:
        InternalStemHunspell(const std::string &apath, const std::string &dpath) : StemImplementation(), handle(NULL) {
            handle = Hunspell_create(apath.c_str(), dpath.c_str());

            this->dic_enc = Hunspell_get_dic_encoding(handle);
            this->toUtf = new IconvWrapper("UTF-8", this->dic_enc);
            this->fromUtf = new IconvWrapper(this->dic_enc, "UTF-8");
        }

        ~InternalStemHunspell() {
            Hunspell_destroy(handle);
        };

        std::string operator()(const std::string &word) {
            char **slist;
            std::string outbuf;
            outbuf = this->fromUtf->convert(word.data());

            int num_slist = Hunspell_stem(handle, &slist, outbuf.c_str());
            for (int i = 0; i < num_slist; i++) {
                const char *c_ptr = slist[i];
                outbuf.assign(c_ptr, strlen(c_ptr));
                outbuf = this->toUtf->convert(outbuf);
                break;
            }
            Hunspell_free_list(handle, &slist, num_slist);
            return outbuf;
        }

        std::string get_description() const {
            return "Hunspell";
        }

    private:
        std::string dic_enc;
        Hunhandle *handle;
        IconvWrapper *toUtf;
        IconvWrapper *fromUtf;

    };
}


#endif //XAPIAN_HUNSPELL_STEMMER_INTERNALSTEMHUNSPELL_H
