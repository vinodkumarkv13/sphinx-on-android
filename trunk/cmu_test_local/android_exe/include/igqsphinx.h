/*
 * igqsphinx.h
 *
 *  Created on: 2011-9-13
 *      Author: root
 */

#ifndef IGQSPHINX_H_
#define IGQSPHINX_H_

#include <stdlib.h>
#include <string>
#include <pocketsphinx.h>

#include <igqrecord.h>


class IGqSphinx {
public:
	IGqSphinx() :
			m_pconfig(NULL), m_pdecoder(NULL) {

	}
	virtual ~IGqSphinx() {
		if (m_pdecoder) {
			ps_free(m_pdecoder);
			m_pdecoder = NULL;
		}
	}

	virtual bool init_sphinx(IGqRecord *precoder) = 0;
	virtual bool start_recognize_from_mic() = 0;
	virtual bool end_recognize_from_mic() = 0;

	virtual std::string get_recognized_str() = 0;

protected:
	cmd_ln_t *m_pconfig;
	ps_decoder_t *m_pdecoder;
};

#endif /* IGQSPHINX_H_ */