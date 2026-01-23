#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Review {
    private:
        int rating;
    public:
        Review(): rating(0) {}
        Review(int r): rating(r) {}
        Review(const Review &rev);
        Review& operator=(const Review &rev);
        bool operator==(const Review &rev) const;
        bool operator!=(const Review &rev) const;
        Review operator+(const Review &rev) const;
        Review operator>(const Review &rev) const;
        Review operator<(const Review &rev) const;
        Review operator>=(const Review &rev) const;
        Review operator<=(const Review &rev) const;


        Review operator++();
        Review operator++(int);

        friend std::ostream& operator<<(std::ostream &os, const Review &rev) {
            os << "Rating: " << rev.rating;
            return os;
        }
        friend std::istream& operator>>(std::istream &is, Review &rev) {
            is >> rev.rating;
            return is;
        }

        int getRating() const { return rating; }
};

Review::Review(const Review &rev)
{
    if (this != &rev) {
        rating = rev.rating;
    }
}
Review& Review::operator=(const Review &rev) {
    if (this != &rev) {
        rating = rev.rating;
    }
    return *this;
}
bool Review::operator==(const Review &rev) const {
    return rating == rev.rating;
}
Review Review::operator+(const Review &rev) const{
    return Review(rating + rev.rating);
}
Review Review::operator++() {
    ++rating;
    return *this;
}
Review Review::operator++(int) {
    Review temp = *this;
    rating++;
    return temp;
}
bool Review::operator!=(const Review &rev) const {
    return rating != rev.rating;
}
Review Review::operator>(const Review &rev) const
{
    return rating > rev.rating;
}
Review Review::operator<(const Review &rev) const
{
    return rating < rev.rating;
}
Review Review::operator>=(const Review &rev) const
{
    return rating >= rev.rating;
}
Review Review::operator<=(const Review &rev) const
{
    return rating <= rev.rating;
}

int main() {
    Review rev1(5);
    Review rev2(3);

    cout << "Review 1: " << rev1 << endl;
    cout << "Review 2: " << rev2 << endl;

    Review rev3 = rev1 + rev2;
    cout << "Combined Review: " << rev3 << endl;

    if (rev1.getRating() > rev2.getRating()) {
        cout << "Review 1 is greater than Review 2" << endl;
    }

    ++rev1;
    cout << "After increment, Review 1: " << rev1 << endl;

    return 0;
}
