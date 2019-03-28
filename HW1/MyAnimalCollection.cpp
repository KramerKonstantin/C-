#include <iostream>
#include <vector>

class MyAnimalCollection {
public:
    explicit MyAnimalCollection(const std::string &name = "Empty Animal List") {
        this->mName = name;
    }

    std::string& setAnimal(const size_t i) {
        return this->mAnimals[i];
    }

    void setAnimalList(const std::vector<std::string> &otherAnimalList) {
        this->mAnimals = otherAnimalList;
    }

    void setName(const std::string &name) {
        this->mName = name;
    }

    std::string getAnimal(const size_t i) const {
        if (i < this->size()) {
            return this->mAnimals[i];
        } else {
            return "[No Animals Here]";
        }
    }

    std::vector<std::string> getAnimalList() const {
        return this->mAnimals;
    }

    std::string getName() const {
        return this->mName;
    }

    void addAnimal(const std::string &animal = "Unknown animal") {
        if (!this->size() && this->mName == "Empty Animal List") {
            this->mName = "Nonempty Animal List";
        }
        mAnimals.push_back(animal);
    }

    void clear(const size_t i) {
        if (this->size()) {
            mAnimals.erase(mAnimals.begin() + i);
        }
        if (!this->size()) {
            this->mName = "Empty Animal List";
        }
    }

    void clear() {
        mAnimals.clear();
        mAnimals.resize(0);
        this->mName = "Empty Animal List";
    }

    size_t size() const {
        return mAnimals.size();
    }

    void print() const {
        if (this->size()) {
            for (size_t i = 0; i < this->size() - 1; ++i) {
                std::cout << this->mAnimals[i] << " | ";
            }
            std::cout << this->mAnimals[this->size() - 1];
        } else {
            std::cout << "[This list is empty]";
        }
        std::cout << std::endl;
    }
private:
    std::string mName;
    std::vector<std::string> mAnimals;
};
