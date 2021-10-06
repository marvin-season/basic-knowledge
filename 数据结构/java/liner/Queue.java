package mawenshu.liner;

public interface Queue {
    void add(Object object);

    Object poll();

    boolean isEmpty();

    boolean isFull();

    int size();
}
