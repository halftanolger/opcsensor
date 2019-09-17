
#
# Dette er bare et eksempel på hvordan man kan sette sammen
# idc_tanktabell_util_data.c og idc_tanktabell_util.c til 'et-eller-annet'.
#

all: util

util:	idc_tanktabell_util_data.o idc_tanktabell_util.o main.o
	gcc idc_tanktabell_util_data.o idc_tanktabell_util.o main.o -o $@

main.o:	main.c
	gcc -Wall -c -I. -I/usr/include $< -o $@

idc_tanktabell_util.o:	idc_tanktabell_util.c
	gcc -Wall -c -I. -I/usr/include $< -o $@

idc_tanktabell_util_data.o:	idc_tanktabell_util_data.c
	gcc -Wall -c -I. -I/usr/include $< -o $@

clean:
	rm *.o
	rm util
