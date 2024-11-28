#ifndef BLA_H
#define BLA_H

class BLA{
private:
    int i{15}; // NOLINT
public:
    [[nodiscard]] int getI() const;
};

#endif // BLA_H
