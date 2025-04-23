# what is story:

 In the land of ancient gods, the Elden Tree is known as the center base; It is responsible for being
a safe place for each god’s events, and it will carefully transform the events between corresponding
lands. But, unfortunately, the previous demi-god programmer who developed the Elden Tree’s
event handler, was a junior and used Js as the base language and it makes the gods angry about
the delays between receiving each event. So, please rewrite and redesign the Elden Tree’s event
handler in C++ ”to be fast 




### Step-by-Step Breakdown of the Problem
Let’s dissect it into manageable parts:

#### 1. Understand the Elden Tree’s Role
What it does: Acts as a hub that receives events and delivers them to the appropriate gods.
Analogy: Think of it as an event dispatcher or message broker (like a postal service for gods).
Key Task: Handle event posting and dispatching quickly and fairly.
##### 2. Define the Components
**Events**: Messages or actions (e.g., "Thunder Strike" for Thor) that need to be processed.
**Needs**: A flexible structure to hold event details (name, data, timestamp, etc.).
**Gods**: The recipients or consumers of events.
**Needs**: A way to identify them and define how they handle events.
**Elden Tree**: The system that ties it all together.
**Needs**: Register gods, store events, and dispatch them efficiently.