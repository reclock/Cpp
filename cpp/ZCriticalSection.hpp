#include <iostream>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <sys/timeb.h>
#include <io.h>
#include <time.h>
#include <stdarg.h>


#define MAXLINSIXE 1600
#define MAXLOGSIZE 20000

CRITICAL_SECTION cs_sec;
static char logstr[MAXLINSIXE+1];
char logfile1[]="log1.log";
char logfile2[]="log2.log";
char datestr[16];
char timestr[16];
char mss[4];
FILE *flog;


void lock(CRITICAL_SECTION *cs){
	EnterCriticalSection(cs);
}
void unlock(CRITICAL_SECTION* cs){
	LeaveCriticalSection(cs);
}

void logV(const char *pszFmt,va_list argp){

	struct tm *now;
	struct timeb tb;

	if(NULL == pszFmt || 0 == pszFmt[0]) return;
	_vsnprintf_s(logstr,MAXLINSIXE,pszFmt,argp);
	ftime(&tb);
	now = localtime(&tb.time);
	sprintf_s(datestr,"%04d-%02d-%02d",now->tm_year+1900,now->tm_mon+1,now->tm_mday);
	sprintf_s(timestr,"%02d:%02d:%02d",now->tm_hour,now->tm_min,now->tm_sec);
	sprintf_s(mss,"%03d",tb.millitm);
	printf("5s %s.%s %s",datestr,timestr,mss,logstr);

	flog = fopen(logfile1,"a");
	if(NULL != flog){
		fprintf(flog,"%s %s.%s %s",datestr,timestr,mss,logstr);
		if(ftell(flog)>MAXLOGSIZE){
			fclose(flog);
			if(rename(logfile1,logfile2)){
				remove(logfile2);
				rename(logfile1,logfile2);
			}
		}else{
			fclose(flog);
		}	
	}
}

void Log(const char *pszFmt,...){
	va_list argp;
	lock(&cs_sec);
	va_start(argp,pszFmt);
	logV(pszFmt,argp);
	va_end(argp);
	unlock(&cs_sec);
}
