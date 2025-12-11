
## **Definition**

Artificial Intelligence is a branch of computer science that aims to create machines or software that can **think**, **learn**, and **make decisions** like humans.

## **Key points to include in definition**

AI systems can perform tasks that normally require human intelligence, such as:

- Problem solving
    
- Learning from experience
    
- Understanding language
    
- Recognizing images or patterns
    
- Making decisions
    

## **Simple example:**

- Google Maps predicting the fastest route
    
- Siri/Alexa understanding your voice
    
- ChatGPT answering your questions
    

---

## **2. Types of AI**

There are **two major ways** to classify AI:

---

### **A. Based on Capability**

#### 1️ Narrow / Weak AI

- Designed to perform **one specific task**
    
- Cannot perform outside its programmed domain
    
- Most AI today is this type  
    **Examples:**
    
- Face recognition
    
- Spam filters
    
- ChatGPT
    
- Self-driving car systems
    

#### **2️⃣ General / Strong AI**

- Can understand, learn, and perform **any intellectual task** that a human can
    
- Still **theoretical**, does not exist yet
    

#### **3️⃣ Super AI**

- An intelligence that surpasses human intelligence in **all aspects**
    
- Can think, reason, plan better than humans
    
- Completely hypothetical
    

---

## **B. Based on Functionality**

### **1️⃣ Reactive Machines**

- No memory
    
- Cannot learn from past experiences
    
- Respond only to the current situation  
    **Example:** IBM Deep Blue (chess computer)
    

### **2️⃣ Limited Memory**

- Can use **past data** for a short time
    
- Most modern AI systems use this  
    **Example:**
    
- Self-driving cars using past frames to detect objects
    

### **3️⃣ Theory of Mind (Future AI)**

- AI that understands emotions, beliefs, intentions
    
- Not yet developed
    

### **4️⃣ Self-Aware AI**

- AI with its own consciousness
    
- Fully hypothetical
    

---

## **3. Turing Test**

### **Definition:**

The **Turing Test**, proposed by **Alan Turing in 1950**, evaluates whether a machine can exhibit **human-like intelligence**.

### **How the test works:**

- A human evaluator talks (via text) to **two entities**:
    
    1. A machine
        
    2. A human
        
- If the evaluator **cannot reliably tell the machine from the human**, the machine is said to have passed the Turing Test.
    

### **Purpose:**

To check if a machine can **think** or **behave like a human** in conversation.

### **Example:**

A chatbot that answers questions so naturally that the evaluator cannot distinguish it from a real human.

---

## **AI TECHNIQUES** 

Artificial Intelligence (AI) uses several techniques to enable machines to think and act intelligently. These techniques help AI systems to **represent knowledge, learn from data, make decisions, search for solutions, and solve complex problems**. The major AI techniques are described below:

---

## **1. Search Techniques**

Search techniques are used when a problem has many possible solutions and the AI system must find the **best or most optimal** one.  
AI treats every problem as a state space, where each state represents a possible configuration.  
Search algorithms explore these states to reach the goal.

### **Types of Search Techniques:**

- **Uninformed (Blind) Search:** These algorithms do not use any prior knowledge.  
    Examples include **Breadth-First Search (BFS)** and **Depth-First Search (DFS)**.
    
- **Informed (Heuristic) Search:** Uses additional knowledge to search faster.  
    Examples include **A* Search, Greedy Search, Hill Climbing**.
    

### **Applications:**

Navigation systems, puzzle solving, robot path planning, game playing, route optimization.

---

## **2. Knowledge Representation Techniques**

For an AI system to behave intelligently, it must store information in a way the machine can understand. This is done through **knowledge representation**.

### **Major types of knowledge representation:**

1. **Semantic Networks** – represent knowledge as graphs with nodes and links.
    
2. **Frames** – store structured information about objects and their attributes.
    
3. **Production Rules (IF–THEN rules)** – used in expert systems for decision-making.
    
4. **Predicate Logic** – uses symbols and logical relationships.
    
5. **Ontologies** – define concepts and relationships in a domain.
    

### **Applications:**

Chatbots, expert systems, reasoning engines.

---

## **3. Reasoning Techniques**

Reasoning is the ability of AI systems to **draw conclusions, make inferences, and solve problems** based on available knowledge.

### **Types of reasoning:**

- **Deductive reasoning:** General → Specific
    
- **Inductive reasoning:** Specific → General
    
- **Abductive reasoning:** Incomplete information → Best possible explanation
    

### **Applications:**

Medical diagnosis, fraud detection, decision support systems.

---

## **4. Machine Learning Techniques**

Machine Learning enables systems to learn patterns from data instead of being explicitly programmed.

### **Types of ML techniques:**

- **Supervised Learning:** Input + Output are provided.  
    Examples: Classification, Regression.
    
- **Unsupervised Learning:** Only input data is provided.  
    Examples: Clustering, Association.
    
- **Reinforcement Learning:** Learning through rewards and penalties.
    

### **Applications:**

Spam filtering, recommendation systems, prediction models.

---

## **5. Problem-Solving Techniques**

These techniques help AI to break down a complex problem into smaller manageable steps.

Examples:

- **State-space approach**
    
- **Means-end analysis**
    
- **Heuristics**
    

Applications: Game playing, planning systems, scheduling.

---

## **6. Neural Networks Techniques**

Artificial Neural Networks (ANNs) are inspired by the human brain. They consist of layers of interconnected nodes that learn patterns from large amounts of data.  
Neural networks form the foundation of **Deep Learning**.

Applications: Image recognition, speech-to-text, NLP systems.

---


## **1. Artificial Intelligence (AI)**

AI is the broadest field. It refers to creating machines that can **perform tasks that normally require human intelligence**, such as reasoning, learning, problem-solving, understanding language, and decision-making.

### **Characteristics of AI:**

- Tries to mimic human intelligence
    
- Includes logic, reasoning, learning, planning, and perception
    
- Not always data-driven (Example: Expert systems, rule-based systems)
    

### **Examples:**

- Chess-playing systems
    
- Expert systems for medical diagnosis
    
- Chatbots
    
- Robotics
    

---

## **2. Machine Learning (ML)**

ML is a subfield of AI concerned with enabling machines to **learn from data**. Instead of writing rules manually, ML algorithms find patterns automatically.

### **Characteristics of ML:**

- Data-driven approach
    
- Improves performance with experience
    
- Includes supervised, unsupervised, and reinforcement learning
    

### **Examples:**

- Spam detection
    
- Credit scoring
    
- Recommendation systems
    
- Weather prediction
    

---

## **3. Deep Learning (DL)**

Deep Learning is a specialized branch of ML that uses **Artificial Neural Networks with many layers**.  
It performs extremely well when large amounts of data are available.

### **Characteristics of DL:**

- Uses multi-layer neural networks (CNNs, RNNs, LSTMs)
    
- Requires high computation power (GPUs/TPUs)
    
- Automatically extracts features from data
    

### **Examples:**

- Face recognition
    
- Speech recognition
    
- Self-driving cars
    
- NLP models like ChatGPT
    
---
##  **TABLE: AI vs ML vs Deep Learning** 

|Feature|Artificial Intelligence|Machine Learning|Deep Learning|
|---|---|---|---|
|Definition|Science of making machines intelligent|Machines learn from data|Uses neural networks to learn from large data|
|Subset Relation|Broadest field|Subset of AI|Subset of ML|
|Data Requirement|Low–Medium|Medium|Very high|
|Approach|Rule-based + learning|Statistical learning|Neural network learning|
|Complexity|Medium|High|Very high|
|Hardware|Normal CPU|CPU/GPU|High-end GPU/TPU|
|Examples|Expert systems, robotics|SVM, Decision Trees|CNN, RNN, LSTM|


# **1. Problem Characterization and Reduction**


Problem characterization and reduction are important AI concepts that help break down complex problems into simpler and more manageable forms. They help an AI system understand the nature of a problem and select the correct strategy to solve it.

## **1. Problem Characterization**

Problem characterization means **describing a problem in a structured and precise manner** so that it can be solved using AI techniques.  

A problem is characterized by identifying:

### **(a) Initial State**

The starting situation of the problem.

### **(b) Goal State**

The final state we want to achieve.

### **(c) Operators (Actions)**

Actions that can be applied to move from one state to another.

### **(d) Path Cost**

The cost associated with a particular solution.
    
### **Example:**

In the 8-puzzle problem:

- Initial state = scrambled tiles
    
- Goal state = tiles arranged in order
    
- Operators = move blank tile up/down/left/right
    
- Path cost = number of moves
    
---
## **2. Problem Reduction**

Problem reduction means **reducing a complex problem into smaller, simpler subproblems**.  
Solving each subproblem helps solve the original large problem.

### **Why Problem Reduction?**

- Difficult problems become easier
    
- Reduces computational cost
    
- Helps reuse solutions to known subproblems
    

### **How Reduction Works:**

1. Identify the main problem
    
2. Break it into subproblems
    
3. Solve each subproblem
    
4. Combine solutions to solve the overall problem
    

### **Example:**

To solve a jigsaw puzzle:

- Separate edge pieces → subproblem
    
- Solve corners → subproblem
    
- Group similar colors → subproblem  
    When combined, the main puzzle is solved.
    
---

## **2. MEA (Means–Ends Analysis)**

Means–Ends Analysis (MEA) is a **problem-solving strategy** used in AI to reduce the difference between the current state and the goal state by selecting appropriate actions (“means”).

## **Definition:**

MEA works by **comparing the current state with the goal state**, identifying differences, and then applying actions (operators) that reduce these differences step-by-step.

---
## **Working of MEA**

### **1. Compare Current State and Goal State**

Find how they differ.

### **2. Select a Difference to Reduce**

Choose the difference that is most important.

### **3. Choose an Operator (Action)**

Select an operator that can reduce that difference.

### **4. Check Preconditions**

If the operator cannot be applied immediately, create a **subgoal** to satisfy the preconditions.

### **5. Apply the Operator**

Move closer to the goal.

### **6. Repeat Until Goal is Achieved**

---
### **Example of MEA**

Goal: Move from City A to City B  
Difference: Location  
Means (operators): Take bus, train, or flight  
MEA selects the operator that **reduces the difference most effectively**, e.g., flight reduces distance fastest.

---
## **3. Ethics of AI**

Ethics of AI refers to the set of **moral principles and guidelines** that govern the development and use of artificial intelligence. As AI systems become more powerful and widely used, it is important to ensure that they are developed responsibly and used for the benefit of society.

---
### **1. Fairness and Bias**

AI systems may become biased if trained on biased data.  
Biased AI can lead to unfair decisions in:

- Hiring
    
- Loan approval
    
- Criminal justice  
    Ensuring fairness requires clean, unbiased datasets.
    

---

### **2. Transparency and Explainability**

AI decisions should be understandable.  
Users should know:

- Why the AI made a decision
    
- How the model works
    
Black-box models (like deep learning) create challenges in transparency.

---

### **3. Privacy and Data Protection**

AI systems use large amounts of data.  
It is important to protect personal data like:

- Identity
    
- Medical records
    
- Location
    

AI developers must follow privacy laws (GDPR, etc.).

---

### **4. Safety and Security**

AI systems must be safe and secure.  
Flaws in AI may cause accidents, especially in:

- Self-driving cars
    
- Medical diagnosis systems
    
- Industrial robots
    

---

### **5. Accountability**

Who is responsible when AI makes a mistake?

- Developer?
    
- User?
    
- Company?
    

Clear laws and guidelines are needed.

---

### **6. Job Loss and Automation**

AI may replace human jobs (cashiers, drivers, etc.).  
Ethical AI must ensure reskilling and creation of new opportunities.

---

### **7. Weaponization of AI**

AI can be used in autonomous weapons.  
This raises serious ethical concerns about:

- Human control
    
- Misuse in warfare

--- 

## AI Searching Techniques

Searching techniques are methods used in AI to explore the state space of a problem.  
A **state space** is the set of all possible states the AI can reach from the initial state.

Two of the most fundamental search techniques in AI are:

1. **Breadth-First Search (BFS)**
    
2. **Depth-First Search (DFS)**
    

These belong to **uninformed/blind search methods**, meaning they do not use any additional knowledge or heuristics.

---

### **1. Breadth-First Search (BFS)**

#### **Definition:**

Breadth-First Search is a search strategy that explores the state space **level by level**.  
It starts from the root (initial state) and explores all nodes at the present depth before moving to the next depth level.

---

#### **Characteristics of BFS**

##### **1. FIFO (Queue) Based**

BFS uses a **queue** → First In, First Out.  
This ensures nodes are expanded in the order they are generated.

##### **2. Complete Search**

BFS **will always find a solution** if one exists.

##### **3. Optimal Search**

BFS is optimal **when all step costs are equal**, because it finds the shallowest (shortest) path first.

##### **4. Time and Space Complexity**

If the branching factor is **b** (number of children per node) and depth is **d**:

- **Time complexity:** O(bᵈ)
    
- **Space complexity:** O(bᵈ) (very high, because it stores all nodes)
    

##### **5. Traversal Order**

Level-wise expansion:  
Root → Level 1 → Level 2 → Level 3 → ...

---

#### **Example of BFS**

Suppose we have a simple graph:

```
      A
    /   \
   B     C
  / \   / \
 D   E F   G
```

BFS Order:  
**A, B, C, D, E, F, G**

It visits nodes level by level.

---

#### **Advantages of BFS**

- Guarantees the shortest path in unweighted graphs
    
- Complete and optimal
    
- Good when goal is near the root
    

---

#### **Disadvantages of BFS**

- Very high memory usage
    
- Slow for deep trees or large state spaces
    

---

### **2. Depth-First Search (DFS)**

#### **Definition:**

Depth-First Search is a search technique that expands the **deepest node first**.  
It goes as far as possible down one branch, and when it cannot go further, it backtracks.

---

#### **Characteristics of DFS**

##### **1. LIFO (Stack) Based**

DFS uses a **stack** → Last In, First Out.  
This allows the search to go deep along one branch.

##### **2. Not Always Complete**

DFS may not find a solution if the search tree is infinite or has loops.

##### **3. Not Optimal**

DFS does NOT guarantee the shortest path.

##### **4. Time and Space Complexity**

If branching factor = **b**, depth = **m**:

- **Time complexity:** O(bᵐ)
    
- **Space complexity:** O(b × m) (much less than BFS)
    

##### **5. Traversal Order**

Goes deep first, then backtracks.

---

####  **Example of DFS**

Using the same tree:

```
      A
    /   \
   B     C
  / \   / \
 D   E F   G
```

One possible DFS Order:  
**A, B, D, E, C, F, G**

(It depends on whether left or right child is chosen first.)

---

#### **Advantages of DFS**

- Very memory efficient compared to BFS
    
- Good for problems with deep solutions
    
- Simple to implement
    

---

#### **Disadvantages of DFS**

- May go into infinite loops
    
- Not complete for infinite search trees
    
- Does not guarantee the shortest path
    

---

### **Difference Between BFS and DFS (Exam Table)**

|Feature|BFS|DFS|
|---|---|---|
|Data Structure Used|Queue (FIFO)|Stack (LIFO)|
|Search Method|Level-by-level|Depth-first|
|Completeness|Complete|Not always complete|
|Optimality|Optimal for equal cost|Not optimal|
|Time Complexity|O(bᵈ)|O(bᵐ)|
|Space Complexity|O(bᵈ)|O(b × m) (lower)|
|Suitable For|Finding shortest path|Large depth, less memory|

---
## **HILL CLIMBING 

Hill Climbing is a **heuristic search technique** used in Artificial Intelligence to solve optimization problems. It is an **iterative improvement algorithm** that starts with an initial solution and moves to a better solution step by step, just like climbing a hill, where the goal is to reach the **highest peak** (optimal solution).

It is also known as **greedy local search** because it always chooses the best immediate step without considering future consequences.

---

### **BASIC IDEA**

Hill Climbing tries to continuously move from the current state to a **neighboring state** that has a **higher value** (or lower if minimizing).  
This is repeated until no better neighboring state exists.

At that point, the algorithm stops.

---

### **STEPS OF HILL CLIMBING ALGORITHM**

1. **Start with an initial state**
    
2. **Evaluate the current state** using a heuristic function
    
3. **Generate neighboring states**
    
4. **Compare the heuristic values** of neighbors
    
5. Move to the neighbor **with the best (highest) heuristic value**
    
6. **Repeat steps 2–5** until:
    
    - No neighbor is better → **stop**
        
    - Peak value is reached
        

---

### **TYPES OF HILL CLIMBING**

#### **1. Simple Hill Climbing**

- Examines neighbors one by one.
    
- Moves to the first neighbor that improves the value.
    
- Very fast but not always optimal.
    

#### **2. Steepest-Ascent Hill Climbing**

- Evaluates **all** neighbors.
    
- Moves to the **best** among them.
    
- More accurate but slower.
    

#### **3. Stochastic Hill Climbing**

- Randomly selects a neighbor.
    
- Useful when there are many possible neighbors.
    

---

### **WORKING EXAMPLE**

Consider the following heuristic values for states around a peak:

```
    12 (Goal - global maximum)
      ^
     / \
   10   9
   ^
  / \
 6   8
 ^
 |
 5 (Start)
```

#### **Step-by-step execution:**

**Initial State = 5**  
Neighbors = 6  
Higher? Yes → Move to **6**

**Current State = 6**  
Neighbors = 8, 10  
Higher? Best is 10 → Move to **10**

**Current State = 10**  
Neighbors = 12  
Higher? Yes → Move to **12**

**Current State = 12**  
Neighbors?  
12 is greater than all neighbors → Stop

Fnal Answer = 12 (local or global maximum depending on graph)

---

### **PROBLEMS WITH HILL CLIMBING**

Hill Climbing can get stuck because it only looks at immediate neighbors.

#### **1. Local Maxima**

A state that is better than neighbors but not the best possible solution.

```
     Peak
      ^
     /
   x   <- stops here but higher peak exists elsewhere
```

#### **2. Plateaus**

Flat surface with equal heuristic values.  
The algorithm cannot decide which direction to move.

```
-----------
   plateau
-----------
```

#### **3. Ridges**

A slope that requires moving in directions that hill climbing does not consider.

---

### **ADVANTAGES OF HILL CLIMBING**

- Simple to implement
    
- Requires very little memory
    
- Works well for many optimization problems
    
- Fast and efficient for local search
    

---

### **DISADVANTAGES**

- Can get stuck in **local maxima**
    
- Cannot handle **plateaus** well
    
- Does not backtrack
    
- Not suitable for complex landscapes
    

---

### **APPLICATIONS OF HILL CLIMBING**

- Travelling Salesman Problem (TSP)
    
- Scheduling problems
    
- Machine learning optimization
    
- Robotics pathfinding
    
- Function maximization
    

---

##  **BEST-FIRST SEARCH**

Best-First Search is a **heuristic search technique** where the algorithm selects the next node to expand **based on the lowest heuristic value (h(n))** or **highest priority**.

It combines the advantages of **Breadth-First Search** and **Depth-First Search**, but uses **heuristic information** to guide the search.

---

### **DEFINITION**

Best-First Search is a **greedy search method** that chooses the next node to expand **based on how close it seems to be to the goal**, according to a heuristic function.

The algorithm always expands the **most promising node first**.

It uses a **priority queue** to store nodes, where nodes with the best heuristic value are expanded first.

---

### **HEURISTIC FUNCTION (h(n))**

A heuristic function estimates **how close a node is to the goal**.  
A lower h(n) means the node seems closer to the goal.

Examples of heuristic values:

- Straight-line distance
    
- Manhattan distance
    
- Rule-based estimation
    

---

### **ALGORITHM STEPS (WRITE THIS IN EXAM)**

1. Initialize an **OPEN** list (priority queue) and add the start node.
    
2. Initialize a **CLOSED** list to store visited nodes.
    
3. Choose the node from OPEN with the **lowest heuristic value**.
    
4. If this node is the goal → STOP.
    
5. Otherwise, expand the node:
    
    - Generate all successors
        
    - Compute their heuristic values
        
    - Insert them into OPEN
        
6. Move the expanded node to CLOSED
    
7. Repeat until the goal is found or OPEN becomes empty.
    

---


### **ADVANTAGES**

1. Efficient and faster than BFS and DFS.
    
2. Uses heuristic information → better decision-making.
    
3. Very effective for large search spaces.
    
4. Can find good solutions quickly.
    

---

### **DISADVANTAGES**

1. Not optimal (does not guarantee shortest path).
    
2. Can get stuck in loops without proper checks.
    
3. Performance depends completely on the quality of the heuristic function h(n).
    
4. Uses a lot of memory because it stores many nodes in OPEN list.
    

---

### **APPLICATIONS**

- Pathfinding in GPS systems
    
- Game playing (Chess, puzzles)
    
- Robot navigation
    
- Web crawling
    
- AI planning systems
    

---
![[Pasted image 20251211160642.png]]

---


## **A* Search Algorithm (A-Star Search) – Exam Ready Answer**

A* Search is one of the most important **informed (heuristic) search algorithms** in Artificial Intelligence.  
It is widely used because it is **complete**, **optimal**, and **efficient**.

A* Search combines the strengths of:

- **Uniform-Cost Search** (uses g(n))
    
- **Greedy Best-First Search** (uses h(n))
    

It chooses the next node based on a function **f(n)** that evaluates both the cost so far and the estimated cost to the goal.

---

### **EVALUATION FUNCTION**

A* uses the following formula:

#### **f(n) = g(n) + h(n)**

Where:

#### **g(n)**

Actual cost from the start node to the current node.

#### **h(n)**

Heuristic function — estimated cost from current node to the goal.  
It must be **admissible** → meaning _h(n) should never overestimate_ the true cost.

#### **f(n)**

Total estimated cost of the cheapest solution _through_ node n.  
A* always expands the node with the **lowest f(n)** value.

---

### **ALGORITHM STEPS 

1. Put the start node in **OPEN** list.
    
2. Repeat until OPEN is empty:
    
    - Select the node with the **lowest f(n)** value from OPEN
        
    - If this node is the goal → STOP
        
    - Otherwise, expand the node
        
    - Calculate f(n) for each successor
        
    - Add successors to OPEN
        
    - Move current node to CLOSED
        
3. Return the path from start to goal using backtracking.
    

A* uses a **priority queue** for OPEN list.

---

# ⭐ **WORKING EXAMPLE (EXAM PERFECT)**

Graph with g(n) and heuristic h(n):

```
Start: S
Goal:  G

     S
    / \
  A     B
 g=2   g=3        (cost from S)
 h=4   h=2        (heuristics)
    \   /
      C
   g=4  h=1
      |
      G
   g=5  h=0
```

Let’s compute f = g + h.

---
### **WHY A* IS OPTIMAL?**

A* is optimal _only if_:

- The heuristic **h(n) is admissible**  
    (never overestimates the true cost)
    
- OR **consistent (monotonic)**  
    (f-values never decrease)
    

This ensures A* finds the lowest-cost path.

---

### **ADVANTAGES**

1. Guarantees optimal solution (if h is admissible)
    
2. More efficient than uniform-cost and best-first search
    
3. Explores only promising paths
    
4. Widely used in real-world applications
    

---

### **DISADVANTAGES**

1. High memory usage because it stores many nodes in OPEN list
    
2. Performance depends on the quality of heuristic
    
3. Can be slow if heuristic is poor
    

---

### **APPLICATIONS**

- GPS navigation systems
    
- Robotics and path planning
    
- Maps and route optimization
    
- Puzzle solving (8-puzzle, 15-puzzle)
    
- AI in games (pathfinding for characters)
    
- Network routing algorithms
    

---

