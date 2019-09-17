

#include <idc_tanktabell_util.h>


extern double idc_tanktabell_data[][2];

void idc_tanktabell_util_create(const char* filename) {

  return;
}


int idc_tanktabell_util_size(void) {

  int teller = 0;

  while (1) {
    if (idc_tanktabell_data[teller][0] == -1 && idc_tanktabell_data[teller][1] == -1) {
      return teller;
    } else {
      teller++;
    }
  }

  return -1;

}


double idc_tanktabell_util_look_up(double index) {

  int teller = 0;
  double err = -1.0;

  while (1) {
    if (idc_tanktabell_data[teller][0] == -1 && idc_tanktabell_data[teller][1] == -1) {
      return err;
    } else if (idc_tanktabell_data[teller][0] == index) {
      return idc_tanktabell_data[teller][1];
    } else {
      teller++;
    }
  }

  return err;

}
