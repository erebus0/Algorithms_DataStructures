package ds;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class LinkedList<T> {
    private Node<T> head;

    public List<T> getAll() {
        List<T> valuesList = new ArrayList<>();

        this.travelList(this.head, valuesList);
        return valuesList;
    }

    private void travelList(Node<T> node, List<T> valuesList) {
        if(Objects.nonNull(node)) {
            valuesList.add(node.getValue());
            travelList(node.getNextNode(), valuesList);
        }
    }

    private void insertLast(Node<T> node, T value) {
        if(Objects.nonNull(node.getNextNode())) {
            insertLast(node.getNextNode(), value);
        } else {
            Node<T> newNode = new Node<>();
            newNode.setValue(value);
            node.setNextNode(newNode);
        }
    }

    public void addFirst(T value) {
        Node<T> newNode = new Node<>();
        newNode.setValue(value);
        newNode.setNextNode(this.head);
        this.head = newNode;
    }

    public void addLast(T value) {
        if(Objects.isNull(this.head)) {
            this.head = new Node<>();
            this.head.setValue(value);
        } else {
            this.insertLast(this.head, value);
        }
    }

    private void removeLast() {
        if(Objects.nonNull(this.head) && Objects.nonNull(this.head.getNextNode())) {
            this.deleteLast(this.head);
        } else if(Objects.nonNull(this.head)) {
            this.head = null;
        }
    }

    private void deleteLast(Node<T> node) {
        if(Objects.nonNull(node.getNextNode().getNextNode())) {
            deleteLast(node.getNextNode());
        } else {
            node.nextNode = null;
        }
    }

    private void removeFirst() {
        if(Objects.nonNull(this.head)) {
            this.head = this.head.getNextNode();
        }
    }

    private static class Node<T> {
        private T value;
        private Node<T> nextNode;

        public T getValue() {
            return value;
        }
        
        public void setValue(T value) {
            this.value = value;
        }

        public Node<T> getNextNode() {
            return nextNode;
        }

        public void setNextNode(Node<T> newNode) {
            if(Objects.nonNull(newNode)) {
                newNode.setNextNode(this.getNextNode());
                this.nextNode = newNode;
            }
        }
    }

    public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<>();
        list.removeFirst();
        list.removeLast();
        list.addFirst(10);
        list.removeFirst();
        list.addLast(5);
        list.addLast(3);
        list.addFirst(2);
        list.addLast(4);
        System.out.println(list.getAll());
        list.removeFirst();
        list.removeLast();
        System.out.println(list.getAll());
    }
}