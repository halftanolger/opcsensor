
#include <idc_tanktabell_util.h>

int main(int argc, char *argv[]) {

  if (argc != 3) {
    printf ("\n");
    printf ("IDC Tanktabell util ver. %d\n", IDC_TANKTABELL_UTIL_VERSION);
    printf ("\n");
    printf (" Usage:\n");
    printf ("  -cf <filename>   Create c-kode (i.e data-array) from file.\n");
    printf ("  -d <index>       Dump data to consoll.\n");
    printf ("  -df <filename>   Dump data to file.\n");
    printf ("\n");
    return 0;
  }

  if (argc == 3 && strncmp(argv[1],"-d",2) == 0) {
    double index = atof(argv[2]);
    printf ("\n");
    printf ("IDC Tanktabell util ver. %d\n", IDC_TANKTABELL_UTIL_VERSION);
    printf ("\n");
    printf ("lookup %f => %f\n", index, idc_tanktabell_util_look_up(index));
    printf ("\n");
  }

  return 0;

}
