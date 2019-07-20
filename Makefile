CFLAGS=-std=c99 -pedantic -D_POSIX_C_SOURCE=200809L -Wall -g
LDFLAGS=

EXAMPLES=$(basename $(shell ls example/*.sh))

svm: svm.c

all: svm examples

clean:
	git clean -Xf

examples: $(EXAMPLES:%.sh=%)

test: svm examples
	@echo -n "testing exampleprog0 ... "
	@test "`./svm <example/exampleprog0`"="4" && echo "passed"
	@echo -n "testing exampleprog1 ... "
	@test "`./svm <example/exampleprog1`"="4" && echo "passed"
	@echo -n "testing exampleprog2 ... "
	@test "`./svm <example/exampleprog2`"="9" && echo "passed"
	@echo -n "testing exampleprog3 ... "
	@test "`./svm <example/exampleprog3`"="3" && echo "passed"
	@echo -n "testing exampleprog4 ... "
	@test "`./svm <example/exampleprog4`"="5101520253035404550556065707580859095100105110115120125130135140145150155160165170175180185190195200205210215220225230235240245250255491419242934394449545964697479848994991041091141191241291341391441491541591641691741791841891941992042092142192242292342392442492543813182328333843485358636873788388939810310811311812312813313814314815315816316817317818318819319820320821321822322823323824324825327121722273237424752576267727782879297102107112117122127132137142147152157162167172177182187192197202207212217222227232237242247252161116212631364146515661667176818691961011061111161211261311361411461511561611661711761811861911962012062112162212262312362412462510" && echo "passed"
	@echo -n "testing exampleprog5 ... "
	@test "`./svm <example/exampleprog5`"="51015202530354045505560657075808590951001051101151201251301351401451501551601651701751801851901952002052102152202252302352402452502554" && echo "passed"
	@echo -n "testing exampleprog6 ... "
	@test "`./svm <example/exampleprog6`"="4" && echo "passed"
	@echo -n "testing exampleprog7 ... "
	@test "`./svm <example/exampleprog7`"="4" && echo "passed"

$(EXAMPLES): %: %.sh
	./$< > $@

.PHONY: all examples clean
