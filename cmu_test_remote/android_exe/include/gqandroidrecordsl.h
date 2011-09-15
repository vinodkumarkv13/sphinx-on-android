/*
 * gqandroidrecordsl.h
 *
 *  Created on: 2011-9-8
 *      Author: root
 */

#ifndef GQANDROIDRECORDSL_H_
#define GQANDROIDRECORDSL_H_

#include <igqrecordcb.h>

class GqAndroidRecordSL: public IGqRecordCB {
public:
	GqAndroidRecordSL();
	virtual ~GqAndroidRecordSL();

private:
	virtual void received_buf_from_recorder(short *record_buf,
			unsigned long buf_size_in_byte);
};

#endif /* GQANDROIDRECORDSL_H_ */
