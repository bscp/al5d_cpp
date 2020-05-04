# decisions
* By making use of mixins there could be multiple AL5D robot models be supported. For example 5D and 6D. This way its easy to swap the communication method serial, console, lambda, ros, name it.
* <code>al5d::SerialTrait<al5d::AL5DBase></code> was chosen over <code>al5d::AL5DBase<al5d::SerialTrait></code> because the AL5DBase constructor should know nothing about serial variables.
