all: 	exploration_dilatation explorationPartielle

exploration_dilatation:	exploration_dilatation.c graphes.c graphes.h
	gcc exploration_dilatation.c graphes.c -o exploration_dilatation

explorationPartielle:	explorationPartielle.c graphes.c graphes.h
	gcc explorationPartielle.c graphes.c -o explorationPartielle

