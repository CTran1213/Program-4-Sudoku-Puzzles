
#pragmaonce

class SudokuFitness: public Fitness
{
    public:
    SudokuFitness();
    int howFit(int sudoku[][]) const;
}