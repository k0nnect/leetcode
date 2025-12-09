func tictactoe(moves [][]int) string {
    rows := [3]int{}
    cols := [3]int{}
    diag, anti := 0, 0

    for i, move := range moves {
        r, c := move[0], move[1]

        // A = +1, B = -1
        player := 1
        if i%2 == 1 {
            player = -1
        }

        rows[r] += player
        cols[c] += player

        if r == c {
            diag += player
        }
        if r+c == 2 {
            anti += player
        }

        if rows[r] == 3 || cols[c] == 3 || diag == 3 || anti == 3 {
            return "A"
        }
        if rows[r] == -3 || cols[c] == -3 || diag == -3 || anti == -3 {
            return "B"
        }
    }

    if len(moves) == 9 {
        return "Draw"
    }
    return "Pending"
}