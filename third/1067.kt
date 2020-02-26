import java.util.*

fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    val inputs = Array(n) { readLine()!! }
    val root = TreeSet<TreeNode>()
    for (i in inputs) {
        val rootName = i.split("\\")[0]
        var rootNode = TreeNode(rootName)
        var isInRoot = false
        for (el in root) {
            if (rootName.equals(el.name)) {
                rootNode = el
                isInRoot = true
                break
            }
        }
        if (!isInRoot) {
            root.add(rootNode)
        }
        if (rootName.length != i.length) {
            rootNode.addChild(i.substring(rootName.length + 1))
        }
    }

    for (el in root) {
        el.printNode(0)
    }
}

class TreeNode: Comparable<TreeNode> {

    var name: String;
    var children: SortedSet<TreeNode>

    constructor(name: String) {
        this.name = name;
        this.children = TreeSet()
    }

    fun addChild(path: String) {
        val childName = path.split("\\")[0]
        var childRoot = TreeNode(childName)
        var isExist = false
        for (child in children) {
            if (childName.equals(child.name)) {
                childRoot = child
                isExist = true
                break
            }
        }
        if (!isExist) {
            children.add(childRoot)
        }
        if (childName.length != path.length) {
            childRoot.addChild(path.substring(childName.length + 1))
        }
    }

    fun printNode(spaces: Int) {
        for (i in 0 until spaces) {
            print(" ")
        }
        println(name)
        for (child in children) {
            child.printNode(spaces + 1)
        }
    }

    override fun compareTo(other: TreeNode): Int {
        return name.compareTo(other.name)
    }
}