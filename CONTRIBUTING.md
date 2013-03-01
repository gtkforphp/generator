# How to contribute

Third-party patches are essential for creating fantastic software. Github is a
great tool for making contributing a little - or a lot - easy and fun. There are
some guidelines that contributors should follow that makes it easier for
everyone to help out.

## Getting Started

* You must have a [GitHub account](https://github.com/signup/free)
* Fork the repository on GitHub
* Try running the tests or generating an extension

## Bugs, Feature Requests, and Tasks (oh my)

If you find an error with the way the generator works, that is a bug. If you
want to add a new feature to the generator or change the way something works,
that is a feature request.

If you think you've found a bug, or have a feature request for G\Generator the
first step is to search to see if someone else has already logged the item in
the [issue tracker](https://github.com/gtkforphp/generator/issues).

If you do find a similar bug or feature request, and have additional information
to add, please leave a comment. Don't comment just to say "me too".

If you don't find your bug or feature request, feel free to create a new issue,
please label it appropriately. Feature requests marked as bugs are pretty likely
to simply be marked as invalid and ignored.

## Making Changes

If you want to work on a feature request or bug yourself:

* Create a feature/bug branch from where you want to base your work.  It works well to have the issue id in the branch name somewhere.
  * You usually want to base off of the master branch.
  * Please avoid working directly on the `master` branch.
  * Check for unnecessary whitespace with `git diff --check` before committing.
  * Make sure your commit messages are in the proper format and include the issue id # in the commit message
* Make sure you have added the necessary tests for your changes.
* Run _all_ the tests to assure nothing else was accidentally broken.

## Submitting Changes

* Push your changes to your bug/feature branch in your fork of the repository.
* Submit a pull request to the repository in the gtkforphp organization.

# Additional Resources

* [General GitHub documentation](http://help.github.com/)
* [GitHub pull request documentation](http://help.github.com/send-pull-requests/)
* #gktforphp IRC channel on freenode.org
