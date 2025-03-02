import os

def print_board(board):
    os.system("cls")
    for row in board:
        print(" | ".join(row))
        print("-" * 5)

def check_winner(board, player):
    # Controlla righe, colonne e diagonali
    for row in board:
        if all(s == player for s in row):
            return True
    for col in range(3):
        if all(row[col] == player for row in board):
            return True
    if all(board[i][i] == player for i in range(3)) or all(board[i][2 - i] == player for i in range(3)):
        return True
    return False

def is_full(board):
    return all(all(cell != " " for cell in row) for row in board)

def main():
    board = [[" " for _ in range(3)] for _ in range(3)]
    current_player = "X"

    while True:
        print_board(board)
        print(f"Turno del giocatore {current_player}")
        row = int(input("Inserisci la riga (0, 1, 2): "))
        col = int(input("Inserisci la colonna (0, 1, 2): "))

        if board[row][col] == " ":
            board[row][col] = current_player
            if check_winner(board, current_player):
                print_board(board)
                print(f"Giocatore {current_player} ha vinto!")
                break
            elif is_full(board):
                print_board(board)
                print("Pareggio!")
                break
            current_player = "O" if current_player == "X" else "X"
        else:
            print("Mossa non valida, riprova.")

if __name__ == "__main__":
    main()
