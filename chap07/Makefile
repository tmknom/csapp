SHELL=/bin/bash
.DEFAULT_GOAL := help

# https://gist.github.com/tadashi-aikawa/da73d277a3c1ec6767ed48d1335900f3
.PHONY: $(shell grep --no-filename -E '^[a-zA-Z0-9_-]+:' $(MAKEFILE_LIST) | sed 's/://')

BASE_PATH = .
BINARY_PATH = $(BASE_PATH)/bin/main
BINARY_OBJECT = $(BASE_PATH)/bin/binary.o

define gcc
	docker run --rm -w /work -v $(PWD):/work gcc gcc -Og -S -o ./bin/main.s ${1} && \
	cat ./bin/main.s | \
	grep -v -e '.size' -e '.globl' -e '.type' -e '.cfi' -e '.LF' -e '.ident' -e '.section' -e '.file' -e '.text'
endef

# Phony Targets

clean: ## Clean
	rm -f $(BINARY_PATH)

run: ## docker run
	docker run -it --rm --cap-add=SYS_PTRACE --security-opt="seccomp=unconfined" -w /work -v $(PWD):/work csapp /bin/bash || true

sum: ## gcc sum.c
	docker run --rm -w /work -v $(PWD):/work gcc gcc -save-temps -Og -o ./bin/main main.c sum.c

symtab: ## gcc symtab.c
	docker run --rm -w /work -v $(PWD):/work gcc gcc -Og -c -o ./bin/symtab.o symtab.c

swap: ## gcc swap.c
	docker run --rm -w /work -v $(PWD):/work gcc gcc -Og -c -o ./bin/swap.o swap.c

mult: ## gcc foo.c bar.c
	docker run --rm -w /work -v $(PWD):/work gcc gcc -fcommon foo.c bar.c

static: ## gcc addvec.c multvec.c
	docker run --rm -w /work -v $(PWD):/work gcc gcc -c addvec.c multvec.c
	docker run --rm -w /work -v $(PWD):/work gcc ar rcs libvector.a addvec.o multvec.o
	docker run --rm -w /work -v $(PWD):/work gcc gcc -c main2.c
	docker run --rm -w /work -v $(PWD):/work gcc gcc -static -o ./bin/main main2.o ./libvector.a

share: ## gcc addvec.c multvec.c
	docker run --rm -w /work -v $(PWD):/work gcc gcc -shared -fpic -o libvector.so addvec.c multvec.c
	docker run --rm -w /work -v $(PWD):/work gcc gcc -o ./bin/main main2.c ./libvector.so


# https://postd.cc/auto-documented-makefile/
help: ## Show help
	@grep --no-filename -E '^[a-zA-Z0-9_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-40s\033[0m %s\n", $$1, $$2}'
