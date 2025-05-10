class Date {
    public:
        Date(int y, int m, int d);
        void display();
        Date operator++(); // 示例：日期自增
    private:
        int year, month, day;
    };