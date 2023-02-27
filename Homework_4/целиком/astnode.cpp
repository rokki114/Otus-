#include <cctype>
#include <iostream>
#include <string>

class ASTNode {
public:
    explicit ASTNode(const std::string& repr)
        : repr_(repr), lhs_{ nullptr }, rhs_{ nullptr } {};

    ASTNode(const std::string& repr, ASTNode* lhs, ASTNode* rhs)
        : repr_(repr), lhs_{ lhs }, rhs_{ rhs } {};

    ASTNode(const ASTNode& other) = delete;

    ASTNode& operator=(const ASTNode& other) = delete;

    ~ASTNode()
    {
        delete lhs_;
        delete rhs_;
    };

    std::string repr() const { return repr_; }

    void print(std::ostream& out) const
        {
        inner_print(out, 0);
    };

private:
    void inner_print(std::ostream& out, size_t indent) const
    {
        if (lhs_) {

            lhs_->inner_print(out, indent + 1);
        }

        for (size_t i = 0; i < indent; ++i) {
            out << "    ";
        }
        out << repr_ << '\n';

        if (rhs_) {
            rhs_->inner_print(out, indent + 1);
        }
    };

    std::string repr_;
    ASTNode* lhs_;
    ASTNode* rhs_;
};

int main()
{
    std::string ab = " ";

    ASTNode a("12");
    ASTNode b("25");
    ASTNode(ab, &a, &b);

}