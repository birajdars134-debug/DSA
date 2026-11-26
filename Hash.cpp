class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size

    def hash_function(self, key):
        return key % self.size

    def insert_without_replacement(self, key):
        index = self.hash_function(key)
        start_index = index

        while self.table[index] is not None:
            if self.table[index] == key:
                print(f"Key {key} already exists at index {index}.")
                return
            index = (index + 1) % self.size
            if index == start_index:
                print("Hash Table is full! Cannot insert", key)
                return

        self.table[index] = key
        print(f"Inserted {key} at index {index}.")

    def insert_with_replacement(self, key):
        index = self.hash_function(key)

        # Case 1: Slot is empty
        if self.table[index] is None:
            self.table[index] = key
            print(f"Inserted {key} at home index {index}.")
            return

        # Case 2: Slot is occupied by a key that does NOT belong to this home index
        existing_key = self.table[index]
        if self.hash_function(existing_key) != index:
            print(f"Replacing {existing_key} at index {index} with {key}.")
            self.table[index] = key
            # Re-insert the displaced key using linear probing
            self.insert_without_replacement(existing_key)
            return

        # Case 3: Slot is occupied by a key with the same home index -> probe linearly
        self.insert_without_replacement(key)

    def search(self, key):
        index = self.hash_function(key)
        start_index = index

        while self.table[index] is not None:
            if self.table[index] == key:
                return index
            index = (index + 1) % self.size
            if index == start_index:
                break
        return -1

    def display(self):
        print("\n--- Hash Table ---")
        for i, val in enumerate(self.table):
            print(f"Index {i}: {val if val is not None else 'EMPTY'}")


if __name__ == "__main__":
    size = int(input("Enter size of the Hash Table: "))
    ht = HashTable(size)

    print("\nSelect Collision Resolution Mode:")
    print("1. Linear Probing WITHOUT Replacement")
    print("2. Linear Probing WITH Replacement")
    mode = int(input("Enter choice (1 or 2): "))

    while True:
        print("\n1. Insert Key\n2. Search Key\n3. Display Table\n4. Exit")
        choice = int(input("Enter operation: "))

        if choice == 1:
            key = int(input("Enter key to insert: "))
            if mode == 1:
                ht.insert_without_replacement(key)
            else:
                ht.insert_with_replacement(key)
        elif choice == 2:
            key = int(input("Enter key to search: "))
            pos = ht.search(key)
            if pos != -1:
                print(f"Key {key} found at index {pos}.")
            else:
                print(f"Key {key} not found.")
        elif choice == 3:
            ht.display()
        elif choice == 4:
            break
        else:
            print("Invalid choice.")
