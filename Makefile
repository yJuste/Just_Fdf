NAME = juste

RESET			= "\033[0m"
GREEN			= "\033[92m"	# Green
RED			= "\033[91m"	# Red

all: $(NAME)

$(NAME):
	git submodule update --init --recursive
	@echo $(GREEN)"The submodules were perfectly installed."$(RESET)

$(HELP):
	@echo $(RED)"Did you import the Submodules ? do `make init`"$(RESET)

.PHONY: all init help
