/*
 * gqrecord.h
 *
 *  Created on: 2011-9-7
 *      Author: root
 */

#ifndef GQRECORD_H_
#define GQRECORD_H_

#include <stdlib.h>


#include <igqrecordcb.h>

class IGqRecord {
public:
	IGqRecord() : m_precordcb(NULL){
	}
	virtual ~IGqRecord() {
	}

public:
	virtual bool init_recorder() = 0;
	virtual bool start_record() = 0;
	virtual bool pause_record() = 0;
	virtual bool stop_record() = 0;

	virtual inline void set_record_cb(IGqRecordCB  *precordcb) {
		m_precordcb = precordcb;
	}

	virtual inline IGqRecordCB* get_record_cb() {
		return m_precordcb;
	}

protected:
	IGqRecordCB  *m_precordcb;

};

#endif /* GQRECORD_H_ */
