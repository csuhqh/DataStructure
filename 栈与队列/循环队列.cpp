template <typename T>
class CircularQueue{
    public:
        CircularQueue(int capacity): m_capacity(capacity){
            elements = new T[capacity];
        }
        ~CircularQueue(){
            delete[] elements;
        }
        bool push(const T& item){
            if(getSize() == m_capacity - 1){
                return false;
            }
            elements[m_rear] = item;
            m_rear += 1;
            m_size += 1;
            return true;
        }
        bool pop(){
            if(isEmpyt()) return false;
            m_front += 1;
            m_size -= 1;
            return true;
        }
        //取头元素
        const T& front() const{
            if(isEmpyt()) throw std::runtime_error("CircularQueue is empty! pop() fail");
            return elements[m_front];
        }
        bool isEmpyt() const{
            return m_size == 0;
        }
        int getSize() const{
            return m_size;
        }
    private:
        T* elements;
        int m_size{0}, m_front{0}, m_rear{0};
        int m_capacity;
};