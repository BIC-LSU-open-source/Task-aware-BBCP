#ifndef __BBCP_PROGMON_H__
#define __BBCP_PROGMON_H__
/******************************************************************************/
/*                                                                            */
/*                        b b c p _ P r o g M o n . h                         */
/*                                                                            */
/*(c) 2002-14 by the Board of Trustees of the Leland Stanford, Jr., University*//*      All Rights Reserved. See bbcp_Version.C for complete License Terms    *//*                            All Rights Reserved                             */
/*   Produced by Andrew Hanushevsky for Stanford University under contract    */
/*              DE-AC02-76-SFO0515 with the Department of Energy              */
/*                                                                            */
/* bbcp is free software: you can redistribute it and/or modify it under      */
/* the terms of the GNU Lesser General Public License as published by the     */
/* Free Software Foundation, either version 3 of the License, or (at your     */
/* option) any later version.                                                 */
/*                                                                            */
/* bbcp is distributed in the hope that it will be useful, but WITHOUT        */
/* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or      */
/* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public       */
/* License for more details.                                                  */
/*                                                                            */
/* You should have received a copy of the GNU Lesser General Public License   */
/* along with bbcp in a file called COPYING.LESSER (LGPL license) and file    */
/* COPYING (GPL license).  If not, see <http://www.gnu.org/licenses/>.        */
/*                                                                            */
/* The copyright holder's institutional names and contributor's names may not */
/* be used to endorse or promote products derived from this software without  */
/* specific prior written permission of the institution or contributor.       */
/******************************************************************************/
  
#include "bbcp_Pthread.h"

class bbcp_File;
class bbcp_ZCX;

class bbcp_ProgMon
{
public:

void  Monitor();

void  Start(bbcp_File *fs_obj, bbcp_ZCX *cx_obj, int pint, long long xfrbytes);

void  Stop();

      bbcp_ProgMon() : FSp(0),CXp(0),wtime(0),Tbytes(0),mytid(0),monDone(0)
                     {}
     ~bbcp_ProgMon() {Stop();}

private:
bbcp_File     *FSp;
bbcp_ZCX      *CXp;
int            wtime;
long long      Tbytes;
pthread_t      mytid;
int            alldone;
bbcp_CondVar   CondMon;
bbcp_Semaphore monDone;
};
#endif
