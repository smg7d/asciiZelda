
SRCS = main.cpp Aquamentus.cpp Blank.cpp Board.cpp Character.cpp Door.cpp Dice.cpp Game.cpp Item.cpp ItemContainer.cpp LikeLike.cpp Link.cpp Menu.cpp Octorok.cpp Rock.cpp Space.cpp Tektite.cpp Vortex.cpp
HEADERS = Aquamentus.h Blank.h Board.h Character.h Door.h Dice.h Game.h Item.h ItemContainer.h LikeLike.h Link.h Menu.h Octorok.h Rock.h Space.h Tektite.h Vortex.h
FLAGS = -std=c++0x


default: ${SRCS} ${HEADERS}
	g++ ${FLAGS} ${SRCS} -o FinalProject

clean:
	rm FinalProject