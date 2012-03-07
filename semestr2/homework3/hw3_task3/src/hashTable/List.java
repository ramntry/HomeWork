package hashTable;

/**
 * use to create List
 *
 * @author vladimir-zakharov
 */
public class List {

    /**
     * elements of List
     */
    public class ListElement {

        /**
         * constructor for ListElement
         *
         * @param value
         * @param next
         * @param prev
         */
        public ListElement(String value, ListElement next, ListElement prev) {
            this.next = next;
            this.prev = prev;
            this.value = value;
        }
        private String value;
        private ListElement next;
        private ListElement prev;
    }

    /**
     * add element to head of list
     *
     * @param value
     */
    public void addToHead(String value) {
        if (count == 0) {
            addFirstElement(value);
        } else {
            ListElement newElement = new ListElement(value, head, null);
            head.prev = newElement;
            head = newElement;
            count++;
        }
    }

    /**
     * add elemet to tail of list
     *
     * @param value
     */
    public void addToEnd(String value) {
        if (count == 0) {
            addFirstElement(value);
        } else {
            ListElement newElement = new ListElement(value, null, tail);
            tail.next = newElement;
            tail = newElement;
            count++;
        }
    }

    /**
     * insert element into list
     *
     * @param position
     * @param value
     */
    public void insert(ListElement position, String value) {
        if (count == 0) {
            addFirstElement(value);
        } else if (position == head) {
            addToHead(value);
        } else if (position == tail) {
            addToEnd(value);
        } else {
            ListElement newElement = new ListElement(value, position.next, position);
            position.next.prev = newElement;
            position.next = newElement;
            count++;
        }
    }

    /**
     * return value of this position
     *
     * @param position
     * @return
     */
    public String PositionValue(ListElement position) {
        return position.value;
    }

    /**
     * return value of head
     *
     * @return
     */
    public String HeadValue() {
        return head.value;
    }

    /**
     * return value of tail
     *
     * @return
     */
    public String TailValue() {
        return tail.value;
    }

    /**
     * delete elment of this position
     *
     * @param position
     */
    public void deleteElement(ListElement position) {
        if (count == 1) {
            head = null;
            tail = null;
        } else if (position == head) {
            position.next.prev = null;
            head = position.next;
        } else if (position == tail) {
            position.prev.next = null;
            tail = position.prev;
        } else {
            position.prev.next = position.next;
            position.next.prev = position.prev;
        }
        count--;
    }

    /**
     * return number of elements
     *
     * @return
     */
    public int amountElements() {
        return count;
    }

    /**
     * return head position
     *
     * @return
     */
    public ListElement firstPosition() {
        return head;
    }

    /**
     * return tail position
     *
     * @return
     */
    public ListElement endPosition() {
        return tail;
    }

    /**
     * return next position
     *
     * @param position
     * @return
     */
    public ListElement nextPosition(ListElement position) {
        return position.next;
    }

    /**
     * return previos position
     *
     * @param position
     * @return
     */
    public ListElement prevPosition(ListElement position) {
        return position.prev;
    }

    /**
     * print List
     */
    public void printList() {
        ListElement temp = head;
        System.out.println("Данный список:");

        while (temp != null) {
            System.out.print(temp.value);
            System.out.print(' ');
            temp = temp.next;
        }

        System.out.println();
    }

    /**
     * add first element of List
     */
    private void addFirstElement(String value) {
        ListElement newElement = new ListElement(value, null, null);
        head = newElement;
        tail = newElement;
        count = 1;
        HashTable hash = new HashTable();
    }
    
    /**
     * head of list
     */
    private ListElement head;
    
    /**
     * tail of list
     */
    private ListElement tail;
    
    /**
     * number of elements
     */
    private int count;
}