#ifndef __IDC_TANKTABELL_UTIL_H__
#define __IDC_TANKTABELL_UTIL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IDC_TANKTABELL_UTIL_VERSION_MAJOR 1
#define IDC_TANKTABELL_UTIL_VERSION_MINOR 0
#define IDC_TANKTABELL_UTIL_VERSION_PATCH 1

#define IDC_TANKTABELL_UTIL_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define IDC_TANKTABELL_UTIL_VERSION \
    IDC_TANKTABELL_UTIL_MAKE_VERSION(IDC_TANKTABELL_UTIL_VERSION_MAJOR, \
                           IDC_TANKTABELL_UTIL_VERSION_MINOR, \
                           IDC_TANKTABELL_UTIL_VERSION_PATCH)


#ifdef __cplusplus
extern "C" {
#endif

void idc_tanktabell_util_create(const char* filename);

int idc_tanktabell_util_size(void);

double idc_tanktabell_util_look_up(double index);

#ifdef __cplusplus
}
#endif


#endif //__IDC_TANKTABELL_UTIL_H_INCLUDED__
