package mawenshu.liner;

public interface List {
    int size();

    boolean isEmpty();

    void add(int index, Object object);

    void add(Object object);

    Object removeByIndex(int index);

    Object remove(Object object);

    Object replaceByIndex(int i, Object object);

    Object replace(Object oldObject, Object newObject);

    Object get(int i);
}
