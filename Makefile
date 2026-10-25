# Builds and (optionally) runs the three MasterChef parts.
#   make          build part-b, part-c and part-d
#   make run      run each part with the scripted input in its sample_input.txt
#   make clean    remove build output
PARTS = part-b part-c part-d

.PHONY: all run clean $(PARTS)

all: $(PARTS)

$(PARTS):
	$(MAKE) -C $@

run: all
	@for p in $(PARTS); do echo "=== $$p ==="; $(MAKE) --no-print-directory -C $$p run; done

clean:
	@for p in $(PARTS); do $(MAKE) --no-print-directory -C $$p clean; done
