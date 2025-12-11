
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


## **A* Search Algorithm (A-Star Search)

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

###  **WORKING EXAMPLE **

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

## Knowledge Representation and Reasoning

Knowledge Representation and Reasoning (KRR) is a core area of Artificial Intelligence concerned with **how knowledge about the world is represented** inside a machine and **how the machine uses that knowledge to draw conclusions**.  
A good representation must be structured, unambiguous, expressive, and suitable for reasoning.

Two major formal approaches are:

- **Propositional Logic (PL)**
    
- **First-Order Predicate Logic (FOPL)**
    

These form the foundation for AI reasoning systems.

---

## Approaches to Knowledge Representation

Knowledge can be represented in different ways such as logic, semantic networks, frames, rules, ontologies, and scripts.  
Here, we focus on **logic-based representation**, which includes:

### Propositional Logic

### First Order Predicate Logic

### Inference Rules

---

## Propositional Logic (PL)

Propositional Logic represents knowledge in the form of simple **true/false statements** (propositions).  
Each proposition is an atomic statement such as:

- “It is raining.”
    
- “The jug is full.”
    

These propositions are represented using symbols like **P, Q, R**, etc.

### Syntax of Propositional Logic

A propositional formula is formed using:

#### Propositional symbols

P, Q, R, …

#### Logical connectives

- **AND ( ∧ )**
    
- **OR ( ∨ )**
    
- **NOT ( ¬ )**
    
- **IMPLIES ( → )**
    
- **BICONDITIONAL ( ↔ )**
    

### Semantics

Each proposition can be **True (T)** or **False (F)**.

### Example

Let:  
P: It is raining  
Q: I will take an umbrella

A rule can be written as:  
P → Q (“If it is raining, I will take an umbrella”)

Propositional logic is easy to compute but limited because it cannot express relationships between objects (e.g., "All humans are mortal").

---

## First-Order Predicate Logic (FOPL)

First-Order Predicate Logic overcomes the limitations of propositional logic by introducing **objects**, **predicates**, and **quantifiers**.  
It can represent more complex knowledge about objects and their relationships.

### Components of FOPL

#### Constants

Specific objects — John, India, Cat

#### Variables

x, y, z (represent unknown objects)

#### Predicates

Functions that describe properties or relations:

- Human(x)
    
- Loves(John, Mary)
    
- GreaterThan(x, y)
    

#### Functions

Father(x), HeightOf(x), etc.

#### Quantifiers

There are two quantifiers:

1. **Universal Quantifier ( ∀ )**  
    Means “for all”  
    Example: ∀x Human(x) → Mortal(x)
    
2. **Existential Quantifier ( ∃ )**  
    Means “there exists”  
    Example: ∃x Loves(John, x)
    

### Example in FOPL

“All humans are mortal.”  
∀x Human(x) → Mortal(x)

“John is a human.”  
Human(John)

Therefore, by reasoning, we conclude:  
Mortal(John)

FOPL is more expressive than PL and is widely used in AI reasoning systems.

---

## Inference Rules

Inference rules allow AI systems to **derive new knowledge** from existing knowledge.  
These rules operate over propositional and predicate logic.

Below are important inference rules used in AI.

---

## Modus Ponens

### Rule

If

1. P → Q
    
2. P
    

Then we can conclude:  
Q

### Example

1. If it rains, the ground becomes wet. (R → W)
    
2. It is raining. (R)  
    Therefore:  
    W (ground becomes wet)
    

---

## Modus Tollens

### Rule

If

1. P → Q
    
2. ¬Q
    

Then we conclude:  
¬P

### Example

1. If it is a dog, it has four legs. (D → F)
    
2. It does not have four legs. (¬F)  
    Therefore:  
    ¬D (it is not a dog)
    

---

## Resolution Rule

Resolution is a fundamental inference rule used in **automated theorem proving**.  
It is based on eliminating complementary literals.

### Basic Form

From  
(P ∨ Q)  
and  
(¬Q ∨ R)

We infer:  
(P ∨ R)

### Example

1. (Hot ∨ Cold)
    
2. (¬Cold ∨ Rain)  
    Resolution gives:  
    (Hot ∨ Rain)
    

Resolution is powerful because it can be used to build complete proof systems.

---

## AND-Elimination

### Rule

From a conjunction:  
(P ∧ Q)

We can conclude:  
P  
or  
Q

### Example

1. (Tall ∧ Smart)  
    We can infer:  
    Tall  
    Smart
    

---

## Syllogism (Hypothetical Syllogism)

Syllogism is a logical rule where conclusions are drawn from two related implications.

### Rule

If  
P → Q  
and  
Q → R

Then  
P → R

### Example

1. If A is a bird, A has wings. (Bird(A) → Wings(A))
    
2. If A has wings, A can fly. (Wings(A) → Fly(A))  
    Therefore:  
    Bird(A) → Fly(A)
    

This shows chained reasoning in logic.

---
## Disjunctive Syllogism

Disjunctive Syllogism is an important inference rule used in Propositional Logic.  
It allows us to draw a valid conclusion when we know that **one of two statements is true**, and we also know that **one of them is false**.  
From this, we infer that the _other_ statement must be true.

---

## Definition

Disjunctive Syllogism states:

From:
1. P∨Q (P OR Q is true)
2. ¬P (P is false)
    

We can conclude:

3. Q
    

Similarly:

If
1. P∨Q
2. ¬Q
    

Then:

3. P
    

It eliminates the false part of a disjunction and concludes the remaining true part.

---



## Example 1

Statement 1: “It is raining or it is sunny.”  
R∨S

Statement 2: “It is not raining.”  
¬R

Conclusion: “It is sunny.”  
S

---

## Example 2

Statement 1:  
“John is at home or John is at office.”  
H∨O

Statement 2:  
“John is not at home.”  
¬H

Conclusion:  
John is at office.  

    

---

## Types of Knowledge

Knowledge in AI can be categorized into several types depending on how it represents reality and how it is used for reasoning.

---

## 1. Declarative Knowledge

Declarative knowledge describes **facts about the world**.  
It answers: _What is true?_

### Examples

- “Delhi is the capital of India.”
    
- “A triangle has three sides.”
    

This type of knowledge can be represented using logic, semantic networks, or ontologies.

---

## 2. Procedural Knowledge

Procedural knowledge specifies **how to perform tasks** or **the steps to accomplish a goal**.  
It answers: _How to do something?_

### Examples

- How to solve a puzzle
    
- How to diagnose a disease
    
- How to drive a car
    

Production rules and scripts are good representations of procedural knowledge.

---

## 3. Meta-Knowledge

Meta-knowledge means **knowledge about knowledge**.  
It tells the system how to choose, organize, or use other pieces of knowledge.

### Example

- “When multiple rules apply, choose the rule with the highest confidence.”
    

Used in expert systems for conflict resolution.

---

## 4. Heuristic Knowledge

Heuristics are **rules of thumb** or **strategies** that help reach solutions quickly, though not guaranteed to be perfect.

### Example

- “In chess, control the center first.”
    
- “If stuck in a search problem, choose the option with the least cost.”
    

Heuristic knowledge makes AI more efficient but not always optimal.

---

## 5. Structural Knowledge

Structural knowledge describes the **relationships between concepts**.

### Examples

- Hierarchies (Animal → Mammal → Dog)
    
- Part-whole structure (Car: engine, wheels, seats)
    

Semantic networks and frames often represent structural knowledge.

---
![[Pasted image 20251211210847.png]]

## Reasoning in AI

Reasoning is the process by which an AI system derives new facts, conclusions, or knowledge from existing information. 

---

## Forward Reasoning (Forward Chaining)

Forward reasoning is a **data-driven** reasoning approach.  
It starts from the **known facts** and applies rules to derive **new conclusions** until the goal is reached.

### How it works

1. Begin with a set of known facts in working memory.
    
2. Match these facts with the IF part of rules.
    
3. When a rule fits, apply it and add the THEN part to working memory.
    
4. Continue applying rules until:
    
    - The desired goal is obtained, or
        
    - No more new facts can be derived.
        

### Characteristics

- Starts from initial data and moves forward.
    
- Useful when all facts are known but the goal is unknown.
    
- Common in **expert systems**, **diagnosis systems**, **monitoring systems**.
    

### Example

Rules:

```
IF fever THEN infection
IF infection THEN prescribe antibiotics
```

Facts: fever  
Using forward reasoning → infection → prescribe antibiotics.

---

## Backward Reasoning (Backward Chaining)

Backward reasoning is **goal-driven**.  
It starts from the **goal** and works backward to see whether the facts support the goal.

### How it works

1. Start with the goal (what you want to prove).
    
2. Look for rules whose THEN part matches the goal.
    
3. Reduce the goal to sub-goals from the IF part.
    
4. Continue until:
    
    - Sub-goals match known facts, or
        
    - No rule can satisfy the goal.
        

### Characteristics

- Starts from goal and works backward.
    
- Efficient when goal is known but data is incomplete.
    
- Used in **theorem proving**, **logic programming**, **Prolog**, **diagnostic reasoning**.
    

### Example

Goal: prescribe antibiotics  
Check rule:

```
IF infection THEN prescribe antibiotics
```

Now need to prove: infection  
Check rule:

```
IF fever THEN infection
```

Since fever is a fact → goal proven.

---

## Difference Between Forward and Backward Reasoning

|Basis|Forward Reasoning|Backward Reasoning|
|---|---|---|
|Approach|Data-driven|Goal-driven|
|Start Point|Known facts|Desired goal|
|Direction|From facts → goal|From goal → facts|
|Best Used When|Many facts available, unclear goal|Specific goal known, fewer facts|
|Efficiency|May generate unnecessary facts|More focused, checks only relevant rules|
|Application|Expert systems, monitoring, prediction|Theorem proving, diagnostics, Prolog|

---

## Monotonic Reasoning

Monotonic reasoning refers to reasoning systems where **adding new information does NOT invalidate previous conclusions**.

### Characteristics

- The set of conclusions can only **increase**, never decrease.
    
- Follows classical logic.
    
- Adding new facts cannot make previous inferences false.
    

### Example

Facts:  
“All birds have wings.”  
“Penguin is a bird.”  
Conclusion: “Penguin has wings.”

If we add new facts, this conclusion remains valid because classical logic does not revise earlier conclusions.

### Where used?

- Mathematical logic
    
- Classical reasoning systems
    
- Traditional expert systems (without exceptions)
    

---

## Non-Monotonic Reasoning

Non-monotonic reasoning allows conclusions to be **withdrawn or modified** when new information arrives.

### Characteristics

- More realistic because real-world knowledge changes.
    
- Adding new facts may invalidate old conclusions.
    
- Supports reasoning with defaults and exceptions.
    

### Example

Default knowledge:  
“Typically, birds fly.”

Facts:  
“Penguin is a bird.”  
We conclude: “Penguin flies.”

But if we add new fact:  
“Penguin cannot fly.”

The earlier conclusion must be retracted.

### Where used?

- Default reasoning
    
- Common-sense reasoning
    
- AI planning and uncertain environments
    
- Expert systems with exceptions
    
- Medical diagnosis, real-world reasoning
    

---

## Difference Between Monotonic and Non-Monotonic Reasoning

|Basis|Monotonic Reasoning|Non-Monotonic Reasoning|
|---|---|---|
|Change in Knowledge|Adding new facts does not change old conclusions|Adding new facts can change or remove old conclusions|
|Behavior|Knowledge only increases|Knowledge may increase or decrease|
|Flexibility|Less flexible, rigid|More flexible, realistic|
|Real-world Fit|Poor representation of changing knowledge|Models real-world uncertainty better|
|Example|Classical propositional/predicate logic|Default logic, defeasible reasoning|
|Conclusion Revision|Never revised|Often revised based on new information|

---

