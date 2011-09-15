/*
 * gqandroidsphinx.h
 *
 *  Created on: 2011-9-13
 *      Author: root
 */

#ifndef GQANDROIDSPHINX_H_
#define GQANDROIDSPHINX_H_

#include <string>

#include <igqsphinx.h>
#include <igqrecord.h>
#include <igqrecordcb.h>


class GqAndroidSphinx : public IGqSphinx, public IGqRecordCB {
public:
	GqAndroidSphinx();
	virtual ~GqAndroidSphinx();


	virtual bool init_sphinx(IGqRecord *precord);
	virtual bool start_recognize_from_mic();
	virtual bool end_recognize_from_mic();

	virtual std::string get_recognized_str();

private:
	virtual void received_buf_from_recorder(short *record_buf,
			unsigned long buf_size_in_byte);

	void destroy_sphinx();

private:
	std::string m_shmm;
	std::string m_slm;
	std::string m_sdict;

	std::string m_srecognized;

	IGqRecord *m_precord;
};

#endif /* GQANDROIDSPHINX_H_ */
