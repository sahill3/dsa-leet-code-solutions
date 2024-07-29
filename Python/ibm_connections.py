def minConnections(userConnections):
    parent = {}

    def find(user):
        if user not in parent:
            parent[user] = user
        if parent[user] != user:
            parent[user] = find(parent[user])
        return parent[user]

    def union(user1, user2):
        parent1 = find(user1)
        parent2 = find(user2)
        if parent1 != parent2:
            parent[parent1] = parent2

    for user1, user2 in userConnections:
        union(user1, user2)

    return len(set(find(user) for user in parent)) - 1

userConnections1 = [
    ["user1", "user2"],
    ["user2", "user3"],
    ["user4", "user5"]
]
print(minConnections(userConnections1))  # Expected Output: 2

userConnections2 = [
    ["user1", "user2"],
    ["user2", "user3"],
    ["user3", "user4"]
]
print(minConnections(userConnections2))  # Expected Output: 0

userConnections3 = [
    ["user1", "user2"],
    ["user3", "user4"],
    ["user4", "user5"],
    ["user5", "user6"]
]
print(minConnections(userConnections3))  # Expected Output: 1
