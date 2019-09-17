
#include <idc_tanktabell_util.h>

int main(int argc, char *argv[]) {

  if (argc != 3) {
    printf ("\n");
    printf ("IDC Tanktabell util ver. %d\n", IDC_TANKTABELL_UTIL_VERSION);
    printf ("\n");
    printf (" Usage:\n");
    printf ("  -cf <filename>   Create c-kode (i.e data-array) from file.\n");
    printf ("  -d <index>       Dump data to consoll.\n");
    printf ("\n");
    printf ("This will do the trick\n");
    printf ("   ./util -cf data.csv > idc_tanktabell_util_data.c \n");
    printf ("   make \n");
    printf ("   ./util -d 123 (this will look up from the new data) \n");
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

  if (argc == 3 && strncmp(argv[1],"-cf",2) == 0) {

    const char* filename = argv[2];

    FILE* fd = 0;
    fd = fopen(filename,"r");
    if (fd == NULL) {
        printf("Could not open file %s",filename);
        return 1;
    }

    char delim[] = ";";
    int max = 1000;
    char str[max];
    printf ("double idc_tanktabell_data[][2] = {\n");
    while (fgets (str, max, fd) != NULL) {
        char *ptrA = strtok (str,delim);
        char *ptrB = strtok (NULL,delim);
        printf("{%s,%s},\n", ptrA,ptrB);
    }
    fclose(fd);
    printf(" {-1.0,-1.0}\n");
    printf("};\n");
    printf("\n");

  }

  return 0;

}
