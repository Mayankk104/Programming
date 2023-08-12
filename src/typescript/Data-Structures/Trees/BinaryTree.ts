class BinaryTree {
    private root: DataNode<number>;

    constructor(root?: DataNode<number>) {
        this.root = new DataNode(1);
    }

    BFS(): void {
        let level = 0;
        if (this.root === null) return;

        const queue: { node: DataNode<number>; level: number }[] = [{ node: this.root, level: 0 }];

        while (queue.length > 0) {
            const curentNode = queue.shift();
            console.log(`${curentNode?.node?.data} at level ${curentNode?.level}`);

            if (curentNode !== undefined && curentNode?.node.left !== null) queue.push({ node: curentNode.node.left, level: curentNode.level + 1 });
            if (curentNode !== undefined && curentNode?.node.right !== null) queue.push({ node: curentNode.node.right, level: curentNode.level + 1 });
        }
    }

    addInitialNodes(): void {
        this.root.left = new DataNode(7);
        this.root.right = new DataNode(0);

        this.root.left.left = new DataNode(7);
        this.root.left.right = new DataNode(-8);
        this.root.right.left = new DataNode(5);
        this.root.right.right = new DataNode(-4);
    }
}

class DataNode<T> {
    data: T | null = null;
    left: DataNode<T> | null = null;
    right: DataNode<T> | null = null;

    constructor(data?: T) {
        if (data !== undefined) this.data = data;
    }
}

const binaryTree = new BinaryTree();
binaryTree.addInitialNodes();
binaryTree.BFS();
