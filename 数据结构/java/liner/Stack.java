package mawenshu.liner;

public interface Stack {
    void push(Object object);

    Object pop();

    Object peek();

    boolean isEmpty();

    boolean isFull();
}
