/*
 * igqrecordcb.h
 *
 *  Created on: 2011-9-13
 *      Author: root
 */

#ifndef IGQRECORDCB_H_
#define IGQRECORDCB_H_

class IGqRecordCB {

public:
	virtual void received_buf_from_recorder(short *record_buf,
			unsigned long buf_size_in_byte) =0;

};


#endif /* IGQRECORDCB_H_ */
