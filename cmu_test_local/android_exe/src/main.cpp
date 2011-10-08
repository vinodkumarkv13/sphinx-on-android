#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>

#include <assert.h>
#include <iomanip>
#include <unistd.h>

#include <pocketsphinx.h>

#include <gqandroidsphinx.h>
#include <gqandroidrecordsl.h>
#include <igqsphinx.h>
#include <gqrecordalsa.h>

#define MODELDIR "/home/q/Workspace/CMUSphinx/SphinxTrain/an4"
//local
int recog_from_file();
void recog_from_mic();

int main(int argc, char *argv[]) {
	int n_which = atoi(argv[1]);

	//std::cout << "please input the record method:" << std::endl;
	//std::cin >> n_which;

	if (n_which > 0) {
		recog_from_mic();
	} else {
		recog_from_file();
	}

	return 0;
}

int recog_from_file() {
	ps_decoder_t *ps;
	cmd_ln_t *config;
	FILE *fh;
	char const *hyp, *uttid;
	int16 buf[512];
	int rv;
	int32 score;

	config = cmd_ln_init(NULL, ps_args(), TRUE, "-hmm",
			MODELDIR "/hmm/model_parameters/an4.ci_cont/", "-lm",
			MODELDIR "/hmm/etc/an4.lm.DMP", "-dict",
			MODELDIR "/hmm/etc/an4.dic", NULL);

	if (NULL == config)
		return 1;
	ps = ps_init(config);

	if (NULL == ps)
		return 1;

	fh = fopen("sphinx_record.raw", "rb");
	if (fh == NULL) {
		perror("Failed to open goforward.raw");
		return 1;
	}

	/*rv = ps_decode_raw(ps, fh, "goforward", -1);
	 if (rv < 0)
	 return 1;
	 hyp = ps_get_hyp(ps, &score, &uttid);
	 if (hyp == NULL
	 )
	 return 1;
	 printf("Recognized: %s\n", hyp);*/

	fseek(fh, 0, SEEK_SET);
	rv = ps_start_utt(ps, "goforward");
	if (rv < 0)
		return 1;
	while (!feof(fh)) {
		size_t nsamp;
		nsamp = fread(buf, 2, 512, fh);
		rv = ps_process_raw(ps, buf, nsamp, FALSE, FALSE);
	}
	rv = ps_end_utt(ps);
	if (rv < 0)
		return 1;
	hyp = ps_get_hyp(ps, &score, &uttid);
	if (hyp == NULL
	)
		return 1;
	printf("Recognized: %s\n", hyp);

	fclose(fh);
	ps_free(ps);
	return 0;
}

void recog_from_mic() {
	IGqSphinx *psphinx = new GqAndroidSphinx;
	IGqRecord *precord = new GqRecordALSA;
	std::cout << "main 1" << std::endl;
	psphinx->init_sphinx(precord);
	std::cout << "main 1.2" << std::endl;
	psphinx->start_recognize_from_mic();

	int a = 0;
	std::cin >> a;

	std::cout << "main 2" << std::endl;
	psphinx->end_recognize_from_mic();

	std::string srecog = psphinx->get_recognized_str();
	std::cout << srecog << std::endl;

	if (precord) {
		delete precord;
	}

	if (psphinx)
		delete psphinx;

}
