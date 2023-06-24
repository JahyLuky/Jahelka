#include "queen.h"

Queen::Queen(char name, char color, const Position &pos)
        : Piece(name, color, pos) {}

Queen *Queen::clone() const {
    return new Queen(*this);
}

// Possible queen directions
const std::vector<Position> move_directions = {
        Position(1, 0),
        Position(0, 1),
        Position(-1, 0),
        Position(0, -1),
        Position(1, 1),
        Position(-1, -1),
        Position(-1, 1),
        Position(1, -1)
};

std::vector<Position> *Queen::possible_moves() {
    // Reset possible moves
    this->moves_.clear();

    int row = this->get_position().row_;
    int col = this->get_position().col_;
    int row_cnt = 0, col_cnt = 0;

    for (const auto &direction: move_directions) {
        row_cnt = row + direction.row_;
        col_cnt = col + direction.col_;

        Position pos(row_cnt, col_cnt);

        while (valid_position(pos)) {

            add_move(pos);
            pos.row_ += direction.row_;
            pos.col_ += direction.col_;
        }
    }

    return &this->moves_;
}
