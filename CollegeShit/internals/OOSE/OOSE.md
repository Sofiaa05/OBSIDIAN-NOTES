

## Unit - 1
### OOSE :
**software development methodology** that applies **object-oriented principles** to the entire **software engineering process**

	- object oriented approach
	- graphic modeling (uml)
	- use case driven (real world use cases)
	- incremental development
---

### Review of Objects and Classes :
#### 1. Class:
- **blueprint or template** that defines the **attributes (data members) and behaviors (methods) of an object.**
```java
class Cat {
	// attributes
	string breed;
	int age;

	//methods
	void purring(){
		sop(" I am " + breed + "I purr when im happiest!" + "i am " + age +"years old");
	}
}
```
 
 #### 2. objects: 
 - **instance** of a class that has actual values assigned to its properties.
 ```java
 public class Main{
	 psvm(...){
		 Cat cat = new Cat();
		 cat.breed="scottish fold";
		 cat.age=4;
		 cat.purring();
	 }
 }
```

#### Class vs object
| Feature           | Class                   | Object                                        |
| ----------------- | ----------------------- | --------------------------------------------- |
| Definition        | A template or blueprint | An instance of a class                        |
| Memory Allocation | No memory is allocated  | Memory is allocated when an object is created |
| Example           | `Cat` class             | `cat` object                                  |

![[Pasted image 20250317202845.png]]

---
###  Links and Association in Object-Oriented Concepts :

#### 1. Links

- **Connection** between two **objects** that interact with each other. 
- Represents an **instance-level relationship** between objects.
#####  Example:

- 2 classes : `Student` and `Course`.
- If a `Student` object (e.g., John) is enrolled in a `Course` object (e.g., OOSE), then the specific connection between **John and OOSE** is a **link**.

#### **2. Association**
- Relationship between two or more classes at the class level. 
- relationship may be **one-to-one, one-to-many, or many-to-many**
- It defines how objects of one class are related to objects of another class.
##### Example:

- A `Student` can be **associated** with only one `Course`.
- A `Course` can have multiple `Students`.


| Feature    | Link                                  | Association                  |
| ---------- | ------------------------------------- | ---------------------------- |
| Level      | Instance level                        | Class level                  |
| Definition | Relationship between specific objects | Relationship between classes |
|            |                                       |                              |
#### Type of Association

1. **Unidirectional Association:**
- one class is aware and associated with another class; the reverse is not true. 
- Example: library-book

2. **Bidirectional Association:**  
- The classes are aware of each other and interact with one another. 
- For example: car - ngine

---

### Aggregation and Composition :
#### 1. Aggregation
special form of Association where:****  

- It represents Has-A’s relationship.
- It is a **unidirectional association**
- In Aggregation, **both entries can survive individually*** which means ending one entity will not affect the other entity. (loosely coupled)
- Library - Book `Library` contains `Book`, but `Book` can exist independently.

![[Pasted image 20250317221119.png]]
#### 2. Composition: 
**restricted form of Aggregation** in which two entities are **highly dependent** on each other.  

- It represents **part-of** relationship.
- Both entities are dependent on each other.
- **Bidirectional association.**
- the composed object **cannot exist** without the other entity.
- car-engine `Car` contains `Engine`, and if `Car` is destroyed, `Engine` is also destroyed.
---
![[Pasted image 20250317221324.png]]
---


---
### Generalisation and Specialisation :
#### 1. Generalisation
- Bottom-up method used to combine two or more classes  into a parent (superclass).

**Key Points**:

- It follows **"IS-A"** relationship.
- The parent class is more **generic**, while the child classes are more **specific**.
- uses **Inheritance** 

![[Pasted image 20250317183000.png]]

#### 2. Specialisation :
- Opposite of generalization. 
- Creating **subclasses** from an existing superclass
- uses inheritance

![[Pasted image 20250317183350.png]]

**UML:**
![[Pasted image 20250317221217.png]]

---
### Inheritance:
- mechanism where **child class (subclass)** derives properties and behaviors from a **parent class (superclass)**.
- This helps in **code reusability** and promotes the **"IS-A" relationship** between classes.
#### Types of Inheritance

1. **Single Inheritance** 
2. **Multilevel Inheritance** → A child inherits from another child class (like a chain).
3. **Hierarchical Inheritance** → Multiple child classes inherit from the same parent.
4. **Multiple Inheritance (Not in Java)** → A child inherits from multiple parents 
5. **Hybrid Inheritance** → Combination of different types 

![[Pasted image 20250317203032.png]]

---
### Polymorphism:

1. **Compile-time Polymorphism (Method Overloading)**
    
    - Methods with the **same name but different parameters**.
    - The method call is determined at compile-time.
    - Achieved using **Method Overloading**.
2. **Runtime Polymorphism (Method Overriding)**
    
    - A **child class redefines** a method from the parent class.
    - The method call is determined at runtime.
    - Achieved using **Method Overriding**.
---

### Abstract Classes :
- can not be instantiated by itself.
- Needs to be inherited
- It may have both abstract (method with no definition only declaration) and non-abstract methods(methods with definition and declaration). 
- Abstract methods must be implemented in subclasses.
- declared using the **“abstract”** keyword in its class definition.
```java
abstract class Animal 
{
    int color;
    // An abstract function
    abstract void makeSound();
    void sleep(){
	    sop("sleeping");
    }
}
class car, class dog.
```

---
### Metadata


- Metadata is **"data about data."** 
- In OOSE, metadata describes **structure, attributes (data types, constraints) and behavior of objects, classes, and relationships** within a software system.
---
### Reusability:
- use existing code in different parts of program. without rewriting new.
- improves efficiency, readability, consistency, reduce redundancy.
- achieved through inheritance, polymorphism.
---
 ---
 
---

## Unit - 2

### Object Oriented Methodologies:
- **approaches to software development** that use **object-oriented principles**
- Main Phases:
1. **Object-Oriented Analysis (OOA)** – Identifies system **requirements** and models real-world entities as objects.  
2. **Object-Oriented Design (OOD)** – Defines the system **architecture**, class structures, and object interactions.  
3. **Object-Oriented Programming (OOP)** – **Implements** the design using an OOP language like Java, Python, or C++.
---
### Rational Unified Process :
- software development process for object-oriented models.
#### features :
-  **Iterative & Incremental** – Development is done in cycles (iterations), improving the software step by step.  
- **Use-Case Driven** – Focuses on real-world scenarios and user interactions.
- **Risk-Driven**
- **Well-Defined Phases**
- reduces cost and prevent wastage of resources

#### Phases :
##### 1. Inception Phase (Project Initiation) :

📌 **Goal:** Define the project scope, user requirements, objectives, and feasibility. 

📌 **Key Activities:**
- Estimate costs, risks, and resource requirements.
- Develop an **initial project plan.**

📌 **Deliverables:**  
- Vision Document  
- Business Case
- Initial Use-Case Model

##### 2. Elaboration phase (Planning & Architecture) :
📌 **Goal:** A detailed evaluation and development plan and diminishes the risks.

📌 **Key Activities:**
- Define the system’s **core architecture**.
- Identify and resolve major risks.
- Refine requirements and project plan.

📌 **Deliverables:**  
- Software Architecture Document  
-  Updated Use-Case Model  
- Risk Analysis Document

##### 3. Construction  Phase (Development & Implementation and testing):
- The project is developed and completed.
- System or source code is created and then testing is done. (unit, integration, and system testing)
- Coding takes place.

📌 **Deliverables:**  
- Executable Software System  
- User Manuals  
- Test Cases & Test Reports
##### 4. Transition Phase (Deployment & Support) :

📌 **Goal:** Deliver to end-users.
📌 **Key Activities:**

- Deploy the software in the production environment.
- Conduct user training
- provide documentation.
- Fix bugs and optimize performance.
- Gather user feedback for future improvements.
-  Beta testing is conducted.

📌 **Deliverables:**  
- Final Product Release  
- Training Materials  
- Maintenance Plan

##### 5. Production 

- The final phase of the model.
- The project is maintained and updated accordingly.
#### Advantages :
- **Better Risk Management** 
 - **High-Quality Software** 
  - **Flexible & Scalable** – Can adapt to different project sizes and complexities.  
- **Efficient Development** – Iterative process allows early feature delivery.
- RUP provides **good documentation**
- Good online support
#### Disadvantages :
- complex
- overhead in documentation
- not suitable for smaller projects
- more dependency on risk management
---
### Traditional Lifecycle Model vs Object-Oriented Lifecycle Model

| **Aspect**                      | **Traditional Lifecycle Model**                                  | **Object-Oriented Lifecycle Model**                                             |
| ------------------------------- | ---------------------------------------------------------------- | ------------------------------------------------------------------------------- |
| **Approach**                    | Focuses on procedural programming                                | OOP                                                                             |
| **Structure**                   | Sequential (waterfall) can be iterative (spiral)                 | uses Iterative and incremental models (e.g., RUP, Agile)                        |
| **Phases**                      | Requirements → Analysis → Design → Coding → Testing → Deployment | OO Analysis → OO Design → OO programming                                        |
| **Design Methodology**          | DFDs and ER Diagrams                                             | UML  diagrams such as Class Diagrams, Sequence Diagrams, and Use Case Diagrams. |
| **Reusability and modularity**  | Low                                                              | High                                                                            |
| **Flexibility and scalability** | low                                                              | high                                                                            |
| **Example Models**              | Waterfall, V-Model, Spiral                                       | Rational Unified Process (RUP)                                                  |

---
### UML (Unified Modeling Language)  :
- **Standardized visual language** used **for modeling software systems.** 
- It helps in **designing, visualizing, and documenting** object-oriented systems.
- Developed in 1990s, to standardize software modeling, as multiple modeling methods existed, leading to inconsistencies. Later, became the **industry standard** for software modeling.
#### Need?
- reduces complexity
- supports OOPs
- facilitating better understanding for non programmers
- improves communication
- time saving
---
### 4+1 view architecture of UML :

- To describe software architecture using multiple perspectives. 
- Ensures that different stakeholders (End-users, developers, system engineers etc.) can understand the system according to their specific needs.

![[Pasted image 20250317221958.png]]

#### Views :
##### 1. Logical View :
- **Focus :** Functional requirements of the system. static modelling
- **UML Diagrams:** class diagrams, object diagrams, and state diagrams.
- **Audiences :** Developers and designers.
##### 2. Process View :
- **Focus :** 
	- system’s run-time behavior and dynamic elements (concurrency, fault tolerance and synchronization.)
	- System processes, their interactions
- **UML Diagrams:** sequence diagrams, activity diagrams, and state transition diagrams.
- **Audiences :** System architects and developers.

##### 3. Development View :
- **Focus :** Software components, modules, and their organization in the development environment.
- **UML Diagrams:** component diagrams and package diagrams.
- **Audiences :** Developers

##### 4. Physical View  :
- **Focus :** 
	- mapping of the software onto the hardware 
	- physical connections between components.
- **UML Diagrams:** deployment diagram
- **Audiences :** System engineer, System administrators

##### +1 Use Case View: 
- **Focus :** How end-users interact with the system.
- **UML Diagrams:** use case diagrams.
- **Audience:** Business analysts, customers, and testers.
---
### Project Management
- planning and monitoring project, adhering to given constraints (time,scope and budget).
- creating project schedule.

![[Pasted image 20250317231025.png]]

#### Phases :
##### 1. Initiation (inception phase in RUP) :
- feasibility study ( economic feasibility, operational feasibility, and technical feasibility)
- system can be implemented or not.
- identify risks.
##### 2. Planning :
- project manager prepares project plan to follow.

**acitvities: **
- cost management
- risk management
- procedure and rules 
- develop project policies
- scheduling:  Gantt charts and PERT charts.
- project documention
- **Work Breakdown Structure (WBS)** – Break the project into small tasks.
##### 3. Execution:
- Develop the software using an appropriate Object oriented lifecycle model like RUP
- explain RUP
##### 4. Project Monitoring and Controlling :
 
 ###### Project Monitoring :
  - Continuously track progress and ensure the project stays on schedule and budget and meeting objective.  

**Activities:**

- Compare actual progress vs. project plan.
- Track cost, resources, and quality.

**Key Aspects of Project Monitoring**

1. **Defining Performance Metrics**
    - use KPI
2. **Tracking Progress**
    
    - Compare actual project performance with the planned schedule and budget.
    - Use tools like Gantt charts, Kanban boards, and dashboards.
3. **Risk Monitoring**
    
4. **Budget Monitoring**
    
5. **Quality Monitoring**
    
	- match customer expectation
    - Conduct regular testing, reviews, and audits.
6. **Resource Management**
    
    - Monitor resource allocation and ensure optimal utilization.

7. **Stakeholder Communication**
    
    - Provide regular updates to stakeholders through reports and meetings.


https://www.geeksforgeeks.org/what-is-monitoring-and-control-in-project-management/#what-is-monitoring-phase-in-project-management
##### 5. Project Closing :

- complete the project and document the results
- Deliver the final product to the client.
- Identify reasons if the project fails (e.g., exceeding budget, changing requirements, exceeding time, fast-changing technology).
---
### UML Diagrams :
#### 1. Structural UML Diagrams:
- focus on the static aspects of a system, such as its components and their relationships.
##### 1. Class Diagrams :
- Represents classes, attributes, methods, and relationships between classes.

![[Pasted image 20250318000315.png]]

###### Multiplicity :
- Indicates the number of instances of one class that can be linked to an instance of the other class. 
- For example, each company will have one or more employees (not zero), and each employee currently works for zero or one companies.

Multiplicity notations are placed near the end of an association.

The different cardinality options are :

- `1` Only 1
- `0..1` Zero or One
- `1..*` One or more
- `*` Many
- `n` n (where n>1)
- `0..n` zero to n (where n>1)
- `1..n` one to n (where n>1)
##### 2. Object Diagram
- represents specific instances of classes and relationships between them at a point of time.
- 
![[Pasted image 20250318000432.png]]
##### 3. Component Diagram :
- Represents the high-level structure of a system, showing dependencies between different components/modules.
-  Interfaces are used by components of the system to communicate with each other.

![[Pasted image 20250318000609.png]]


##### 4. Deployment Diagram :
- Shows the physical deployment of software on hardware.

![[Pasted image 20250318000708.png]]

##### 5. Package Diagram :
- Organizes classes into related groups (packages)
```diff
+----------------+
|   Package: UI  |
+----------------+
| - LoginForm    |
| - RegisterForm |
+----------------+

```

#### 1. Behavioral UML Diagrams :
- describe the dynamic aspects of a system, such as interactions and workflows.
##### 1. Use Case Diagram :
**Key Components of Use Case Modeling**

✅ **Actors** – Represent external entities that interact with the system. These can be:

- **Primary Actors:** Users who initiate a use case (e.g., Customer).
- **Secondary Actors:** Systems or users supporting the process (e.g., Payment Gateway).

✅ **Use Cases** – Specific actions or processes that an actor performs in the system.

- **Example:** "Login," "Place Order," "Make Payment."

✅ **Relationships** – interaction between use cases and actors.

- **Association:** Direct interaction between actor and use case.
- **Include:** One use case calls another as a common function (e.g., "Login" is included in "Checkout"). (checkout--<\<include>>->payment)
- **Extend:** A use case may optionally extend another (e.g., "Apply Discount" extends "Make Payment"). (make payment<--<\<extend>>--apply discount)
##### 2. Activity Diagram:
- Represents workflows, like a flowchart.

![[Pasted image 20250318001917.png]]

##### 3. Sequence Diagram :
Shows how objects interact over time.

![[Pasted image 20250318002012.png]]

##### 4. State Diagram :
- Represents different states of an object.

![[Pasted image 20250318002136.png]]