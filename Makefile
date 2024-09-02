CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -lncurses

SRC_DIR = src
BLD_DIR = build
TARGET = tetris


# Trova tutti i file sorgente
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# Crea una lista di file oggetto corrispondenti
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))


all: $(BUILD_DIR)/$(TARGET)

# Regola per la creazione del target finale
$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS)

# Regola per la creazione dei file oggetto
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR) # Crea la cartella build se non esiste
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/$(TARGET)


run: $(BUILD_DIR)/$(TARGET)
	./$(BUILD_DIR)/$(TARGET)

.PHONY: all clean run
