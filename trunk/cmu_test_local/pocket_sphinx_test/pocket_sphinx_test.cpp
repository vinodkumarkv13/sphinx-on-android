//============================================================================
// Name        : pocket_sphinx_test.cpp
// Author      : g
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <pocketsphinx.h>


int main(void) {
    cmd_ln_t *config = cmd_ln_init(NULL,ps_args(),TRUE,
    		"-hmm", "/home/q/Workspace/CMUSphinx/pocketsphinx/model/hmm/zh/zh_broadcastnews_16k_ptm256_8000/",
    		"-lm",  "/home/q/Workspace/CMUSphinx/pocketsphinx/model/lm/zh_CN/zh_broadcastnews_utf8/zh_broadcastnews_64000_utf8.DMP",
    		"-dict","/home/q/Workspace/CMUSphinx/pocketsphinx/model/lm/zh_CN/zh_broadcastnews_utf8/zh_broadcastnews_utf8.dic",
    		NULL);
    if (config == NULL) {
		return 1;
	}

    ps_decoder_t *ps = ps_init(config);
    if (ps == 0) {
		return 1;
	}

    FILE *fh;
    fh = fopen("/home/q/Workspace/CMUSphinx/pocketsphinx/test/data/aaa.wav","rb");
    if (fh == 0) {
    	perror("failed to open goforward.raw");
		return 1;
	}

    int rv = ps_decode_raw(ps,fh,"goforward_t",-1);
    if (rv < 0) {
		return 1;
	}

    char const *hyp,*uutid;
    int32 score;
    hyp = ps_get_hyp(ps,&score,&uutid);
    if (hyp == NULL) {
		return 1;
	}

    printf("recognized: %s\n",hyp);

	return 0;
}
