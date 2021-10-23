#ifndef RANDOM_ENGINE_H
#define RANDOM_ENGINE_H
#include "random"

namespace pawelo {
    template<class T>
    class RandomEngine {
    public:
        RandomEngine(T min, T max) : min_(std::min(min, max)), max_(std::max(min, max)), gen_([] {
            std::random_device rd;
            std::seed_seq seedseq{rd(), rd(), rd(), rd(), rd(), rd()};
            return std::mt19937_64(seedseq);
        }()) {
            if (std::is_floating_point<T>()) {
                real_ = std::uniform_real_distribution<>(min, max);
                is_float_ = true;
            } else if (std::is_integral<T>()) {
                int_ = std::uniform_int_distribution<>(min, max);
                is_float_ = false;
            } else {
                real_ = std::uniform_real_distribution<>(min, max);
                is_float_ = true;
            }
        }

        ~RandomEngine() = default;

        RandomEngine(const RandomEngine &) = delete;

        RandomEngine &operator=(const RandomEngine &) = delete;

        T operator()() {
            // TODO without flag is_float_
            if (is_float_)
                return real_(gen_);
            else {
                return int_(gen_);
            }
        }

    protected:
        std::mt19937_64 gen_;
        bool is_float_;
        std::uniform_int_distribution<> int_;
        std::uniform_real_distribution<> real_;
        T min_ = 0;
        T max_ = 0;
    };
}

#endif // RANDOM_ENGINE_H