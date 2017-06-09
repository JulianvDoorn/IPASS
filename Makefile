.PHONY: clean All

All:
	@echo "----------Building project:[ week-3 -  ]----------"
	@cd "week-3" && "$(MAKE)" -f  "week-3.mk"
clean:
	@echo "----------Cleaning project:[ week-3 -  ]----------"
	@cd "week-3" && "$(MAKE)" -f  "week-3.mk" clean
