# Inventory

## Note:
 Having designed and implemented the player and saddlebag inventories for RDR2, I felt I could not properly do an inventory justice within the scope of the exam.  The Inventory I was creating seemed very scant compared to RDR2's system.  However it is definitely a fun exercise to design an inventory!

## Design Questions
1. Categories: The design of an inventory is heavily dependent on the UI and presentation of that inventory.  
For instance, does the inventory have categories (RDR2) or just one giant list (Fallout).  This would influence how item tags and types are handled and consequently how search queries inside the inventory are handled.
2. Item Groupings: Similarly, are items that are the same grouped together, if so is there a size to a bundle of such an item, or is each item treated individually and not grouped?  This would handle how we update the inventory hashmap.  In Red Dead Redemption we had different item categories and then within those groupings we also had folders.  The number of items can affect how much organization and grouping is required for a user-friendly experience.
3. Number of Inventories:  Does this inventory interact with other inventories?  For instane, in RDR2 we had to track items in  multiple inventories: Player satchel, Player holding (shoulder or hands), back of Horse, primary horse saddlebags, secondary horse saddlebags.  Can you lose your inventory?  How do you reclaim lost or dropped items?
4. Item Animations: Do items have unique pickup animations or do they all use the same animation?
5. For this inventory specifically I was thinking the player should not be allowed to place bags in bags, that is, bags can only be placed in the top inventory.  Otherwise, bags in bags makes searching for items more complex, and likely would result in a frustrating user experiencce.

## Program Structure:
(This is as far as I got)
Three main classes:
Inventory
Item
Bag which is derived from Inventory and Item.

