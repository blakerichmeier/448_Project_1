READ ME for battleship EECS 448
-- includes class information

**Executive**
- interacts with user and runs program
  Executive() - constructor
  runApp() - runs program, contains interaction with other classes
           - post condition: winner declaration
  exitApp() - prints a notification that the user has asked to exit
  
  
**gameBoard**
- contains all variables and functions related to the board display and tracking hits, ship number, etc.
  GameBoard() - constructor
              - post condition: object
  GameBoard(int p_rows, int p_cols, int n_ships)
  ~GameBoard()
  set_rows(int row)
  set_col(int col)
  set_ships(int n_ship)
  set_totalHits(int total_hits)
  get_rows()
  get_col()
  get_ships()
  get_char(int p_row, int p_col)
  get_totalHits()
  get_currHits()
  get_shipArr()
  printPlayBoard(bool inst)
  printShipBoard()
  printInstructions()
  printLegend()
  print_play(char arr)
  printHeader()
  printDotted()
  setGameSpace(int p_row, int p_col, char arr)
  isValidMove(char test_char)
  isShipHere()
  place_ship_return(Ship p_ship, int control)
  check_winner()
  

**main**
- directs to executive class to begin running the program
  main() - creates exec object and runs runApp

**ship**
- holds information about each individual ship, creates ship object
  Ship(int s_len, int s_col, int s_row, char s_dir)
  set_length(int len)
  set_row(int r)
  set_col(int c)
  set_direction(char dir)
  get_id()
  get_length()
  get_col()
  get_row()
  get_direction()
  
**user_input**
- class for communicating with user on all variables in order to play the game
  user_input()
  setRow(int p_row)
  setColumn(int p_col)
  setShipSize(int p_size)
  setShipChar(char p_char)
  setMoveDir(bool p_dir)
  setNumShips(int p_ships)
  getRow()
  getColumn()
  getShipSize()
  getShipChar()
  getMoveDir()
  getNumShips()
  let_2_num(char convert)
  domainCheck(string convert)
  getShip_Input()
  getShipDir_Input()
  getMove_Input()
  getNumShips_Input()
  pause()
