SHELL=/bin/bash
.DEFAULT_GOAL := help

# https://gist.github.com/tadashi-aikawa/da73d277a3c1ec6767ed48d1335900f3
.PHONY: $(shell grep --no-filename -E '^[a-zA-Z0-9_-]+:' $(MAKEFILE_LIST) | sed 's/://')

BASE_PATH = ..
BINARY_PATH = $(BASE_PATH)/bin/main
BINARY_OBJECT = $(BASE_PATH)/bin/binary.o

# Phony Targets

clean: ## Clean
	rm -f $(BINARY_PATH)

print: binary ## Build and run print.c
	gcc -o $(BINARY_PATH) print.c $(BINARY_OBJECT) && $(BINARY_PATH)

binary: ## Build binary.c
	gcc -o $(BINARY_OBJECT) -c binary.c

show_bytes: ## Build and run show_bytes.c
	gcc -o $(BINARY_PATH) show_bytes.c && $(BINARY_PATH)

sum: ## Build and run sum.c
	gcc -o $(BINARY_PATH) -c sum.c && hexdump -C $(BINARY_PATH)

inplace_swap: ## Build and run inplace_swap.c
	gcc -o $(BINARY_PATH) inplace_swap.c && $(BINARY_PATH)

mask: ## Build and run mask.c
	gcc -o $(BINARY_PATH) mask.c && $(BINARY_PATH)

bis_bic: ## Build and run bis_bic.c
	gcc -o $(BINARY_PATH) bis_bic.c && $(BINARY_PATH)

equal: ## Build and run equal.c
	gcc -o $(BINARY_PATH) equal.c && $(BINARY_PATH)

integer: ## Build and run integer.c
	gcc -o $(BINARY_PATH) integer.c $(BINARY_OBJECT) && $(BINARY_PATH)

bit_shift: ## Build and run bit_shift.c
	gcc -o $(BINARY_PATH) bit_shift.c $(BINARY_OBJECT) && $(BINARY_PATH)

truncating: ## Build and run truncating.c
	gcc -o $(BINARY_PATH) truncating.c $(BINARY_OBJECT) && $(BINARY_PATH)

uadd_ok: ## Build and run uadd_ok.c
	gcc -o $(BINARY_PATH) uadd_ok.c $(BINARY_OBJECT) && $(BINARY_PATH)

tadd_ok: ## Build and run tadd_ok.c
	gcc -o $(BINARY_PATH) tadd_ok.c $(BINARY_OBJECT) && $(BINARY_PATH)

tmult_ok: ## Build and run tmult_ok.c
	gcc -o $(BINARY_PATH) tmult_ok.c $(BINARY_OBJECT) && $(BINARY_PATH)

div16: ## Build and run div16.c
	gcc -o $(BINARY_PATH) div16.c $(BINARY_OBJECT) && $(BINARY_PATH)

# https://postd.cc/auto-documented-makefile/
help: ## Show help
	@grep --no-filename -E '^[a-zA-Z0-9_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-40s\033[0m %s\n", $$1, $$2}'
