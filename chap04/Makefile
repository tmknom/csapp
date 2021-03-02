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

define yas
	docker run --rm -w /work -v $(PWD):/work gcc:csapp /opt/sim/misc/yas ${1}.ys
endef

define ssim
	docker run --rm -w /work -v $(PWD):/work gcc:csapp /opt/sim/seq/ssim ${1}.yo
endef

# Phony Targets

clean: ## Clean
	rm -f $(BINARY_PATH)

run: ## docker run
	docker run -it --rm -w /work -v $(PWD):/work gcc:csapp /bin/bash || true

asum: ## yas asum
	$(call yas,asum)
	$(call ssim,asum)

abssum: ## yas abssum
	$(call yas,abssum)
	$(call ssim,abssum)

# https://postd.cc/auto-documented-makefile/
help: ## Show help
	@grep --no-filename -E '^[a-zA-Z0-9_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-40s\033[0m %s\n", $$1, $$2}'
