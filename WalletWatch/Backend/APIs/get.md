### Template You Can Use For Any GET Request
```js
exports.getData = async (req, res) => {
  try {
    const data = await Model.find({ filter });
    res.status(200).json(data);
  } catch (error) {
    res.status(500).json({ message: "Error", error: error.message });
  }
};
```

--- 
