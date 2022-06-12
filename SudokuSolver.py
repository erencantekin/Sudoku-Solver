def display_board(board):
    for i in range(len(board)):
        if i > 0 and i % 3 == 0 and i != len(board)-1:
            for k in range(len(board[i]) + (len(board[i])//3)-1):
                print(" -",end="")
            print()
        for j in range(len(board[i])):
            if j % 3 == 0 and j >0:
                print(" |", board[i][j], end="")
            else:
                print(" " + str(board[i][j]), end="")
        print()


def find_empty(board):
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] == 0:
                return (i,j)

    return None


def check(board, value, position):
    for i in range(len(board[0])):
        if board[position[0]][i] == value and position[1] != i:
            return False

    for j in range(len(board)):
        if board[j][position[1]] == value and position[0] != j:
            return False

    box_row = position[1] // 3
    box_column = position[0] // 3

    for i in range(3*box_column, 3*box_column + 3):
        for j in range(3*box_row, 3*box_row + 3):
            if board[i][j] == value and (i,j) != position:
                return False

    return True


def solveSudoku(board):
    empty = find_empty(board)
    if not empty:
        return True
    else:
        empty_pos = empty

    for i in range(1,10):
        if check(board, i, empty_pos):
            board[empty_pos[0]][empty_pos[1]] = i

            if solveSudoku(board):
                return True

            board[empty_pos[0]][empty_pos[1]] = 0

    return False


row_x = int(input("Enter row: "))
row_y = int(input("Enter column: "))
board = []

for i in range(row_x):
    board_list = []
    for j in range(row_y):
        board_list.append(int(input()))
    board.append(board_list)


solveSudoku(board)
display_board(board)
